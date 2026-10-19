savedcmd_log_levels.mod := printf '%s\n'   log_levels.o | awk '!x[$$0]++ { print("./"$$0) }' > log_levels.mod
