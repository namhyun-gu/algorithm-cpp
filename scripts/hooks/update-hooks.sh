#!/bin/bash
echo "[INFO] Update hooks"
hooks=("pre-commit")

for hook in $hooks
do
  echo "Update $hook"
  cp ./scripts/hooks/$hook ./.git/hooks/$hook
done

echo "Update Finished"