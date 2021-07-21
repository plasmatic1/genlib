# Move everything into one file
# Note that testlib.h is also preprocessed into the final genlib.hpp file after, so no need to include testlib.h

# Assumes python3 and python3-pip are installed
# Does NOT work on windows

pip3 show online-judge-verify-helper > /dev/null
if [ $? -eq 1 ]; then
  echo "Required package online-judge-verify-helper not installed"
  pip3 install online-judge-verify-helper
fi

oj-bundle _genlib.hpp > genlib.hpp
