import numpy as np
import subprocess

def generate_testcase(cdo_countr: tuple[int, int], moneyr: tuple[int, int], mbs_countr: tuple[int, int]):
  cdo_count = np.random.randint(cdo_countr[0], cdo_countr[1])
  money = np.random.randint(moneyr[0], moneyr[1])
  cdo = []

  for _ in range(cdo_count):
    mbs_count = np.random.randint(mbs_countr[0], mbs_countr[1])
    once = np.random.randint(1, max((money * 1000) // (cdo_count * 5), 100))

    cdo.append((mbs_count, once, [
      [
        np.random.randint(1, max((money * 1000) // (cdo_count * 3), 1000)),
        np.random.randint(6, 32),
        float("{:.4f}".format(np.random.rand()))
      ]
      for _ in range(mbs_count)
    ]))

  return (cdo_count, money, cdo)

testcases = []

for _ in range(5):
  testcases.append(generate_testcase(cdo_countr = [1, 11], moneyr = [5, 11], mbs_countr = [1, 11]))

for _ in range(5):
  testcases.append(generate_testcase(cdo_countr = [11, 31], moneyr = [10, 16], mbs_countr = [11, 21]))

for _ in range(5):
  testcases.append(generate_testcase(cdo_countr = [31, 51], moneyr = [16, 20], mbs_countr = [21, 26]))

for idx, testcase in enumerate(testcases):
  with open(f'inputs/input{idx:02d}.txt', 'w') as f:
    text = f"{testcase[0]} {testcase[1]}\n"

    for cdo in testcase[2]:
      text += f"{cdo[0]} {cdo[1]}\n"
      text += "\n".join(f"{mbs[0]} {mbs[1]} {mbs[2]}" for mbs in cdo[2])
      text += "\n"

    f.write(text)

for i in range(15):
  with open(f"./outputs/output{i:02d}.txt", 'w') as f:
    input_file = open(f"./inputs/input{i:02d}.txt", "r", encoding="utf-8")

    try:
      res = subprocess.run(
        ["./a.out"], # compiled file path
        input = input_file.read(),
        capture_output=True,
        text=True,
        check=True
        #cwd=r"question folder path if needed"
      )

      f.write(res.stdout)

    finally:
      input_file.close()
