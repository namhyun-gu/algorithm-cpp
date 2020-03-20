#!/bin/bash
echo "[INFO] Fetch hooks"
hooks=("pre-commit")

for hook in $hooks
do
  echo "Fetched $hook"
  cp ../.git/hooks/$hook ./$hook
done