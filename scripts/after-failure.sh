echo "after-failure..."

cd build/tests
ls -al

COREFILE=$(find . -maxdepth 1 -name "core*" | head -n 1)
if [[ -f "$COREFILE" ]]; then 
  echo "core file found: $COREFILE"
  gdb -c "$COREFILE" -ex "thread apply all bt" -ex "set pagination 0" -batch || echo "no gdb found" 
else
  echo "no core file found"
fi 

