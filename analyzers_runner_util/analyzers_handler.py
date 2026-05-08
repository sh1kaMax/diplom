from analyzers.clang_static_analyzer    import ClangStaticAnalyzer
from analyzers.cppcheck                 import CppcheckAnalyzer
from analyzers.flaw_finder              import FlawfinderAnalyzer
from analyzers.frama_c                  import FramaCAnalyzer
from analyzers.infer                    import InferAnalyzer
from analyzers.rats                     import RATSAnalyzer
from analyzers.sparse                   import SparseAnalyzer
from analyzers.splint                   import SplintAnalyzer
from analyzers.pvs_studio               import PVSStudio
from analyzers.ikos                     import IkosAnalyzer
from analyzers.esbmc                    import ESBMCAnalyzer

class AnalyzersHandler:
    def __init__(self):
        self.analyzers_map = {
            "clang-static-analyzer":    ClangStaticAnalyzer,
            "cppcheck":                 CppcheckAnalyzer,
            "flawfinder":               FlawfinderAnalyzer,
            "frama-c":                  FramaCAnalyzer,
            "infer":                    InferAnalyzer,
            "rats":                     RATSAnalyzer,
            "sparse":                   SparseAnalyzer,
            "splint":                   SplintAnalyzer,
            "pvs-studio":               PVSStudio,
            "ikos":                     IkosAnalyzer,
            "esbmc":                    ESBMCAnalyzer
        }

    def get_analyzer_by_name(self, analyzer_name):
        analyzer_constructor = self.analyzers_map.get(analyzer_name.lower())

        if analyzer_constructor is None:
            raise ValueError(f"Такой анализатор '{analyzer_name}' не найден")
        return analyzer_constructor()
    