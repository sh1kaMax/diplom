import json
import pandas as pd
from dash import Dash, dcc, html
from dash.dependencies import Input, Output
import plotly.express as px
import plotly.graph_objects as go
import os

analyzers = ["cppcheck", "flawfinder", "frama-c", "rats", "infer", "splint"]
results_path = "results"
rows = []

for analyzer in analyzers:
    path = f"{results_path}/{analyzer}/{analyzer}_all_results.json"
    if not os.path.exists(path):
        print(f"Файл не найден: {path}")
        continue

    with open(path, "r") as f:
        data = json.load(f)

    for cwe, vals in data["tests_result"].items():
        TP = vals.get("correct_positive_tests", 0)
        AP = vals.get("all_positive_tests", 0)
        TN = vals.get("count_negative_tests", 0)
        AN = vals.get("all_negative_tests", 0)

        FN = AP - TP
        FP = AN - TN

        TPR = TP / (TP + FN) if TP + FN > 0 else 0 
        TNR = TN / (TN + FP) if TN + FP > 0 else 0
        FPR = FP / (FP + TN) if FP + TN > 0 else 0
        Precision = TP / (TP + FP) if TP + FP > 0 else 0
        Recall = TPR
        F1 = (2 * Precision * Recall) / (Precision + Recall) if Precision + Recall > 0 else 0

        rows.append([analyzer, cwe, TP, FP, TN, FN, TPR, TNR, FPR, Precision, Recall, F1])

df = pd.DataFrame(rows, columns=[
    "analyzer", "cwe", "TP", "FP", "TN", "FN",
    "TPR", "TNR", "FPR", "Precision", "Recall", "F1"
])
df["total_tests"] = df["TP"] + df["FP"] + df["TN"] + df["FN"]

print(f"Данные загружены: {len(df)} строк")

app = Dash(__name__)

app.layout = html.Div([

    html.H1("Статические анализаторы — дашборд", style={"textAlign": "center"}),

    html.Div([
        html.Label("Выберите анализаторы:"),
        dcc.Checklist(
            id="analyzer-checklist",
            options=[{"label": a, "value": a} for a in analyzers],
            value=["cppcheck"],  # default
            inline=True
        )
    ], style={"width": "80%", "margin": "auto"}),

    dcc.Graph(id="tpr-bar"),
    dcc.Graph(id="tnr-bar"),
    dcc.Graph(id="bubble-chart"),
    dcc.Graph(id="radar-chart"),
    dcc.Graph(id="heatmap-f1")
])


@app.callback(
    Output("tpr-bar", "figure"),
    Output("tnr-bar", "figure"),
    Output("bubble-chart", "figure"),
    Output("radar-chart", "figure"),
    Output("heatmap-f1", "figure"),
    Input("analyzer-checklist", "value")
)
def update_graphs(selected_analyzers):

    selected_df = df[df["analyzer"].isin(selected_analyzers)]

    # --- TPR BAR (все выбранные) ---
    fig_tpr = px.bar(
        selected_df,
        x="cwe",
        y="TPR",
        color="analyzer",
        barmode="group",
        title="TPR сравнение выбранных анализаторов",
        labels={"TPR": "TPR"}
    )

    # --- TNR BAR ---
    fig_tnr = px.bar(
        selected_df,
        x="cwe",
        y="TNR",
        color="analyzer",
        barmode="group",
        title="TNR сравнение выбранных анализаторов",
        labels={"TNR": "TNR"}
    )

    # --- Bubble chart ---
    fig_bubble = px.scatter(
        selected_df,
        x="TPR",
        y="FPR",
        size="total_tests",
        color="analyzer",
        hover_name="cwe",
        title="Bubble Chart: TPR vs FPR (выбранные анализаторы)",
        labels={"TPR": "TPR", "FPR": "FPR"}
    )

    # --- Radar chart ---
    fig_radar = go.Figure()
    for analyzer in selected_analyzers:
        sub = df[df["analyzer"] == analyzer]
        fig_radar.add_trace(go.Scatterpolar(
            r=sub["F1"],
            theta=sub["cwe"],
            fill='toself',
            name=analyzer
        ))

    fig_radar.update_layout(
        polar=dict(radialaxis=dict(visible=True, range=[0, 1])),
        title="Radar Chart F1-score (выбранные анализаторы)"
    )

    # --- Heatmap ---
    heat_df = df[df["analyzer"].isin(selected_analyzers)] \
        .pivot_table(index="cwe", columns="analyzer", values="F1")

    fig_heat = px.imshow(
        heat_df,
        text_auto=True,
        aspect="auto",
        color_continuous_scale="Viridis",
        title="F1-score Heatmap (только выбранные анализаторы)"
    )

    return fig_tpr, fig_tnr, fig_bubble, fig_radar, fig_heat


if __name__ == "__main__":
    app.run(debug=True)
