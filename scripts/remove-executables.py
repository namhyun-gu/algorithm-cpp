import os

exclude_list = [".git", "scripts", ".vscode", ".clang-format"]

def search_executables(path: str):
  file_list = os.listdir(path)
  executables = []
  for file in file_list:
    file_path: str = os.path.join(path, file)
    if file in exclude_list:
      continue
    if os.path.isdir(file_path):
      child_files = search_executables(file_path)
      executables += child_files
    else:
      ext = os.path.splitext(file)
      if os.access(file_path, os.X_OK) and ext[1] == '':
        executables.append(file_path)
  return executables

executables = search_executables(".")
for executable_path in executables:
  os.remove(executable_path)
  os.system(f"git add {executable_path}")

print(f"{len(executables)} files removed.")
