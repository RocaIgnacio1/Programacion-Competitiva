import sys
import os
import subprocess

RED = '\033[31m'
GREEN = '\033[32m'
ENDCOLOR = '\033[0m'
[p, in_file] = sys.argv[1], sys.argv[2]

print("Compiling..")
os.system(f"g++ -o a {p}")
lines = open(in_file, "r").readlines()

test = []
expected = []
s = "#IN\n"
case = 1
passed = 0

for line in lines:
    if line == "\n":
        continue
    if s == "#IN\n":
        test.append(line)
    if s == "#OUT\n":
        expected.append(line)
    if s == "#END\n":
        print("\nCASE: ", case, " ", end="")
        e = ''.join(expected[0:len(expected)-1]).strip()
        result = subprocess.run(
            ['./a'],
            input=''.join(test[0:len(test)-1]),
            capture_output=True,
            text=True,
            check=False
        )
        output = result.stdout.strip()
        if output != e:
            print(f"{RED}FAIL{ENDCOLOR}")
            print(f"expected:\n{e}")
            print(f"recived:\n{output}")
            passed += 1
        else:
            print(f"{GREEN}PASS{ENDCOLOR}")
        test = []
        expected = []
        case += 1

    if line in ["#OUT\n", "#IN\n", "#END\n"]:
        s = line

if case == passed:
    color = GREEN
else:
    color = RED
print(f"{color}{passed}/{case} tests passed{ENDCOLOR}")
