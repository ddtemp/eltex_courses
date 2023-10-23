ps -e -o pid,ppid,cmd --no-headers | awk '$2 == 1 && /systemd/'
