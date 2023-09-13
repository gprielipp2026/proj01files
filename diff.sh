#!/usr/bin/env bash
echo $1 | ./readppm > _your_file_
echo $2 | ./readppm > _test_file_
diff -s -C0 _your_file_ _test_file_
rm -f _your_file_
rm -f _test_file_
