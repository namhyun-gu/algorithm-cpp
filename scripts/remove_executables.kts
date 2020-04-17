import java.io.File

val excludes = listOf(".git", ".idea", ".vscode", "scripts", ".clang-format")
val path = if (args.contains("-d")) args[1 + args.indexOf("-d")] else "."

fun search(path: String): List<File> {
    val current = File(path)
    if (!current.isDirectory)
        return emptyList()

    val executables = mutableListOf<File>()
    val files = current.listFiles { file ->
        !excludes.contains(file.name)
    }
    for (file in files) {
        if (file.isDirectory) {
            executables += search(file.path)
        } else {
            if (file.canExecute() && file.extension.isEmpty()) {
                executables.add(file)
            }
        }
    }
    return executables
}

val executables = search(path)
for (executable in executables) {
    executable.delete()
    Runtime.getRuntime().exec("git add ${executable.path}")
    println("${executable.path} found.")
}

println("${executables.size} files removed.")