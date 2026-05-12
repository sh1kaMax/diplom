import json
import pandas as pd
from dash import Dash, dcc, html
from dash.dependencies import Input, Output
import plotly.express as px
import plotly.graph_objects as go
import os

analyzers = ["cppcheck", "frama-c", "splint", "infer", "flawfinder", "rats", "clang-static-analyzer", "pvs-studio", "sparse", "ikos", "esbmc"]
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

# ========== РАСЧЕТ СРЕДНЕГО F1 ДЛЯ КАЖДОГО АНАЛИЗАТОРА ==========
print("\n" + "="*60)
print("АНАЛИЗ СРЕДНИХ ЗНАЧЕНИЙ F1-МЕРЫ ПО АНАЛИЗАТОРАМ")
print("="*60)

# Рассчитываем среднюю F1 для каждого анализатора
avg_f1_by_analyzer = df.groupby('analyzer')['F1'].mean().sort_values(ascending=False)

print("\n📊 Средняя F1-мера по всем CWE (от лучшего к худшему):")
print("-" * 50)
for i, (analyzer, avg_f1) in enumerate(avg_f1_by_analyzer.items(), 1):
    # Определяем уровень качества
    if avg_f1 >= 0.7:
        rating = "🏆 Отлично"
    elif avg_f1 >= 0.5:
        rating = "👍 Хорошо"
    elif avg_f1 >= 0.3:
        rating = "⚠️ Удовлетворительно"
    else:
        rating = "❌ Плохо"
    
    print(f"{i:2}. {analyzer:25} | F1 = {avg_f1:.4f} | {rating}")

print("-" * 50)
print(f"\n📈 Средняя F1 по ВСЕМ анализаторам: {df['F1'].mean():.4f}")

# Дополнительная статистика по каждому анализатору
print("\n" + "="*60)
print("ДЕТАЛЬНАЯ СТАТИСТИКА ПО КАЖДОМУ АНАЛИЗАТОРУ")
print("="*60)

for analyzer in analyzers:
    analyzer_data = df[df['analyzer'] == analyzer]
    if len(analyzer_data) > 0:
        avg_f1 = analyzer_data['F1'].mean()
        median_f1 = analyzer_data['F1'].median()
        max_f1 = analyzer_data['F1'].max()
        min_f1 = analyzer_data['F1'].min()
        std_f1 = analyzer_data['F1'].std()
        
        # Какие CWE анализатор находит лучше всего
        best_cwe = analyzer_data.nlargest(3, 'F1')[['cwe', 'F1']]
        
        print(f"\n📌 {analyzer}:")
        print(f"   Средняя F1: {avg_f1:.4f}")
        print(f"   Медианная F1: {median_f1:.4f}")
        print(f"   Макс F1: {max_f1:.4f}")
        print(f"   Мин F1: {min_f1:.4f}")
        print(f"   Стандартное отклонение: {std_f1:.4f}")
        print(f"   Лучшие CWE: {', '.join([f'{cwe} ({f1:.3f})' for cwe, f1 in best_cwe.values])}")
    else:
        print(f"\n📌 {analyzer}: НЕТ ДАННЫХ")

print("\n" + "="*60)
print("РЕКОМЕНДАЦИИ НА ОСНОВЕ АНАЛИЗА")
print("="*60)

# Рекомендации на основе среднего F1
top_3 = avg_f1_by_analyzer.head(3).index.tolist()
if len(df[df['F1'] > 0.8]) > 0:
    excellent = avg_f1_by_analyzer[avg_f1_by_analyzer >= 0.7].index.tolist()
    print(f"\n🏆 Лучшие анализаторы (F1 > 0.7): {', '.join(excellent)}")
print(f"\n📋 Топ-3 по средней F1: {', '.join(top_3)}")

# Находим анализатор с самой стабильной работой (наименьшее std)
if len(df) > 0:
    most_stable = df.groupby('analyzer')['F1'].std().dropna().idxmin()
    print(f"\n🎯 Самый стабильный анализатор (наименьший разброс): {most_stable}")

print("\n" + "="*60)

# ========== ДАШБОРД DASH ==========
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

    selected_df['TPR_vis'] = selected_df['TPR'].apply(lambda x: 0.01 if x < 0.01 else x)
    selected_df['TNR_vis'] = selected_df['TNR'].apply(lambda x: 0.01 if x < 0.01 else x)

    # --- TPR BAR (все выбранные) ---
    fig_tpr = px.bar(
        selected_df,
        x="cwe",
        y="TPR_vis",
        color="analyzer",
        barmode="group",
        title="TPR сравнение выбранных анализаторов",
        labels={"TPR_vis": "TPR"}
    )

    # --- TNR BAR ---
    fig_tnr = px.bar(
        selected_df,
        x="cwe",
        y="TNR_vis",
        color="analyzer",
        barmode="group",
        title="TNR сравнение выбранных анализаторов",
        labels={"TNR_vis": "TNR"}
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
    app.run(debug=True, host='0.0.0.0', port=1335)
