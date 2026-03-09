import os

ROOT_DIR = "./tests/sa-tests-db/basic_set/c/lang6-mem-leak"
EXTENSIONS = (".c", ".cpp")

def has_flaw_comment(file_path):
    try:
        with open(file_path, "r", encoding="utf-8", errors="ignore") as f:
            for line in f:
                if "// FLAW" in line:
                    return True
    except Exception as e:
        print(f"[ERROR] {file_path}: {e}")
    return False


def rename_file(file_path, is_positive):
    dir_name, filename = os.path.split(file_path)
    name, ext = os.path.splitext(filename)

    if name.endswith("_positive") or name.endswith("_negative"):
        return

    suffix = "_positive" if is_positive else "_negative"
    new_name = name + suffix + ext
    new_path = os.path.join(dir_name, new_name)

    os.rename(file_path, new_path)
    print(f"[RENAMED] {filename} -> {new_name}")


def process_directory(root_dir):
    for root, _, files in os.walk(root_dir):
        for file in files:
            if file.endswith(EXTENSIONS):
                full_path = os.path.join(root, file)
                is_positive = has_flaw_comment(full_path)
                rename_file(full_path, is_positive)


if __name__ == "__main__":
    process_directory(ROOT_DIR)
