#include "BuildSystem.h"

#include <QProcess>

BuildSystem::BuildSystem()
{
}

QString BuildSystem::build()
{
    QString log;

    log += "=== 3DS Builder Studio ===\n";

    QString output;

    // Exemplo.
    // Depois substitua por arm-none-eabi-gcc,
    // 3dsxtool e makerom.

#ifdef Q_OS_WIN
    runCommand("cmd",
               {"/c", "echo Compilando projeto..."},
               output);
#else
    runCommand("echo",
               {"Compilando projeto..."},
               output);
#endif

    log += output;

    log += "\nBuild finalizado.\n";

    return log;
}

bool BuildSystem::runCommand(const QString &program,
                             const QStringList &arguments,
                             QString &output)
{
    QProcess process;

    process.start(program, arguments);

    process.waitForFinished(-1);

    output =
        process.readAllStandardOutput() +
        process.readAllStandardError();

    return process.exitCode() == 0;
}
