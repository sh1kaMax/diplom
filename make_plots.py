import json
import pandas as pd
import plotly.express as px
import plotly.graph_objects as go
import os

analyzers = ["cppcheck", "flawfinder", "frama-c", "rats", "infer", "splint"]
results_path = "results"
save_dir = "plots"
os.makedirs(save_dir, exist_ok=True)

rows = []

for analyzer in analyzers:
    path = f"{results_path}/{analyzer}/{analyzer}_all_results.json"
    if not os.path.exists(path):
        print(f"Файл не найден: {path}")
        continue

    with open(path, "r") as f:
        data = json.load(f)

    for cwe, vals in data["tests_result"].items():
        TP = vals["correct_positive_tests"]
        AP = vals["all_positive_tests"]
        TN = vals["count_negative_tests"]
        AN = vals["all_negative_tests"]

        FN = AP - TP
        FP = AN - TN

        TPR = TP / (TP + FN) if TP + FN > 0 else 0 
        TNR = TN / (TN + FP) if TN + FP > 0 else 0
        FPR = FP / (FP + TN) if FP + TN > 0 else 0
        Precision = TP / (TP + FP) if TP + FP > 0 else 0
        Recall = TPR
        F1 = (2 * Precision * Recall) / (Precision + Recall) if Precision + Recall > 0 else 0

        rows.append([
            analyzer, cwe, TP, FP, TN, FN, TPR, TNR, FPR, Precision, Recall, F1
        ])

df = pd.DataFrame(rows, columns=[
    "analyzer", "cwe", "TP", "FP", "TN", "FN",
    "TPR", "TNR", "FPR", "Precision", "Recall", "F1"
])

print("Загружено:", len(df), "строк")

# TPR TNR
fig = px.bar(
    df,
    x="cwe",
    y="TPR",
    color="analyzer",
    barmode="group",
    title="True Positive Rate (TPR) по каждому CWE"
)
fig.write_html(f"{save_dir}/1_tpr_bar.html")

fig = px.bar(
    df,
    x="cwe",
    y="TNR",
    color="analyzer",
    barmode="group",
    title="True Negative Rate (TNR) по каждому CWE"
)
fig.write_html(f"{save_dir}/2_tnr_bar.html")


# Heatmap
heat_df = df.pivot_table(
    index="cwe", columns="analyzer", values="F1"
)

fig = px.imshow(
    heat_df,
    text_auto=True,
    aspect="auto",
    color_continuous_scale="Viridis",
    title="Heatmap F1-score по CWE и анализаторам"
)
fig.write_html(f"{save_dir}/3_heatmap_f1.html")


# Radar of every analyzer
for analyzer in analyzers:
    sub = df[df["analyzer"] == analyzer]

    fig = go.Figure()

    fig.add_trace(go.Scatterpolar(
        r=sub["F1"],
        theta=sub["cwe"],
        fill='toself',
        name=analyzer
    ))

    fig.update_layout(
        polar=dict(radialaxis=dict(visible=True)),
        title=f"Radar chart F1-score — {analyzer}"
    )

    fig.write_html(f"{save_dir}/radar_{analyzer}.html")


# Bubble
df["total_tests"] = df["TP"] + df["FP"] + df["TN"] + df["FN"]

fig = px.scatter(
    df,
    x="TPR",
    y="FPR",
    size="total_tests",
    color="analyzer",
    hover_name="cwe",
    title="Bubble Chart: TPR vs FPR (размер = кол-во тестов)"
)
fig.write_html(f"{save_dir}/4_bubble_tpr_fpr.html")

print(f"Готово! Все графики сохранены в папку: {save_dir}")
