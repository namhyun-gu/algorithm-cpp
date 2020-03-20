#!/bin/bash
echo "[INFO] Update hooks"
hooks=("pre-commit")

for hook in $hooks
do
  echo "Update $hook"
  cp ./$hook ../.git/hooks/$hook
done