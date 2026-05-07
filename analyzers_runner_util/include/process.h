/* process.h - Эмуляция Windows process.h для Linux (исправленная версия) */
#ifndef _PROCESS_H_
#define _PROCESS_H_

#include <unistd.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <stdlib.h>

/* Константы режимов запуска (Windows) */
#ifndef _P_WAIT
    #define _P_WAIT     0
#endif
#ifndef _P_NOWAIT
    #define _P_NOWAIT   1
#endif
#ifndef _P_OVERLAY
    #define _P_OVERLAY  2
#endif
#ifndef _P_DETACH
    #define _P_DETACH   3
#endif

/* _spawnlp - ищет в PATH, запускает с переменным числом аргументов */
static inline int _spawnlp(int mode, const char *file, const char *arg0, ...) {
    pid_t pid;
    int status;
    char *args[64];
    va_list ap;
    int i = 1;
    
    if (!file || !arg0) return -1;
    
    args[0] = (char *)arg0;
    va_start(ap, arg0);
    while (i < 63 && (args[i] = va_arg(ap, char *)) != NULL) {
        i++;
    }
    va_end(ap);
    args[i] = NULL;
    
    if (mode == _P_OVERLAY) {
        execvp(file, args);
        return -1;
    }
    
    pid = fork();
    if (pid == 0) {
        execvp(file, args);
        _exit(127);
    } else if (pid < 0) {
        return -1;
    }
    
    if (mode == _P_WAIT) {
        waitpid(pid, &status, 0);
        return status;
    }
    return pid;
}

/* _spawnl - полный путь, не ищет в PATH */
static inline int _spawnl(int mode, const char *path, const char *arg0, ...) {
    pid_t pid;
    int status;
    char *args[64];
    va_list ap;
    int i = 1;
    
    if (!path || !arg0) return -1;
    
    args[0] = (char *)arg0;
    va_start(ap, arg0);
    while (i < 63 && (args[i] = va_arg(ap, char *)) != NULL) {
        i++;
    }
    va_end(ap);
    args[i] = NULL;
    
    if (mode == _P_OVERLAY) {
        execv(path, args);
        return -1;
    }
    
    pid = fork();
    if (pid == 0) {
        execv(path, args);
        _exit(127);
    } else if (pid < 0) {
        return -1;
    }
    
    if (mode == _P_WAIT) {
        waitpid(pid, &status, 0);
        return status;
    }
    return pid;
}

/* _execv - заменяет процесс, массив аргументов */
static inline int _execv(const char *path, char *const *argv) {
    if (!path) return -1;
    return execv(path, argv);
}

/* _execvp - заменяет процесс, ищет в PATH */
static inline int _execvp(const char *file, char *const *argv) {
    if (!file) return -1;
    return execvp(file, argv);
}

/* _execl - заменяет процесс, список аргументов */
static inline int _execl(const char *path, const char *arg0, ...) {
    char *args[64];
    va_list ap;
    int i = 1;
    
    if (!path || !arg0) return -1;
    
    args[0] = (char *)arg0;
    va_start(ap, arg0);
    while (i < 63 && (args[i] = va_arg(ap, char *)) != NULL) {
        i++;
    }
    va_end(ap);
    args[i] = NULL;
    
    return execv(path, args);
}

/* _execlp - заменяет процесс, ищет в PATH */
static inline int _execlp(const char *file, const char *arg0, ...) {
    char *args[64];
    va_list ap;
    int i = 1;
    
    if (!file || !arg0) return -1;
    
    args[0] = (char *)arg0;
    va_start(ap, arg0);
    while (i < 63 && (args[i] = va_arg(ap, char *)) != NULL) {
        i++;
    }
    va_end(ap);
    args[i] = NULL;
    
    return execvp(file, args);
}

/* _spawnv - полный путь, массив аргументов */
static inline int _spawnv(int mode, const char *path, char *const *argv) {
    pid_t pid;
    int status;
    
    if (!path) return -1;
    
    if (mode == _P_OVERLAY) {
        execv(path, argv);
        return -1;
    }
    
    pid = fork();
    if (pid == 0) {
        execv(path, argv);
        _exit(127);
    } else if (pid < 0) {
        return -1;
    }
    
    if (mode == _P_WAIT) {
        waitpid(pid, &status, 0);
        return status;
    }
    return pid;
}

/* _spawnvp - ищет в PATH, массив аргументов */
static inline int _spawnvp(int mode, const char *file, char *const *argv) {
    pid_t pid;
    int status;
    
    if (!file) return -1;
    
    if (mode == _P_OVERLAY) {
        execvp(file, argv);
        return -1;
    }
    
    pid = fork();
    if (pid == 0) {
        execvp(file, argv);
        _exit(127);
    } else if (pid < 0) {
        return -1;
    }
    
    if (mode == _P_WAIT) {
        waitpid(pid, &status, 0);
        return status;
    }
    return pid;
}

/* _spawnve - с переменными окружения */
static inline int _spawnve(int mode, const char *path, char *const *argv, char *const *envp) {
    pid_t pid;
    int status;
    
    if (!path) return -1;
    
    if (mode == _P_OVERLAY) {
        execve(path, argv, envp);
        return -1;
    }
    
    pid = fork();
    if (pid == 0) {
        execve(path, argv, envp);
        _exit(127);
    } else if (pid < 0) {
        return -1;
    }
    
    if (mode == _P_WAIT) {
        waitpid(pid, &status, 0);
        return status;
    }
    return pid;
}

/* Для широких символов (wchar_t) - простой маппинг */
#ifdef _UNICODE
    #define wspawnlp _spawnlp
    #define wspawnl _spawnl
    #define wexecl _execl
    #define wexeclp _execlp
#endif

#endif /* _PROCESS_H_ */