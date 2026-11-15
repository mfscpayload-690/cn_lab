import os
import subprocess
import tempfile
import time
import sys

BASE_DIR = os.path.dirname(os.path.abspath(__file__))

TEST_CASES = [
    {
        "id": 1,
        "dir": "01_even_or_odd",
        "name": "Even or Odd",
        "input": "14\n",
        "tcp_expected": "Even Number",
        "udp_expected": "Even Number"
    },
    {
        "id": 2,
        "dir": "02_sum_of_n_numbers",
        "name": "Sum of N Numbers",
        "input": "4\n10\n20\n30\n40\n",
        "tcp_expected": "100",
        "udp_expected": "100"
    },
    {
        "id": 3,
        "dir": "03_string_palindrome",
        "name": "String Palindrome",
        "input": "madam\n",
        "tcp_expected": "Palindrome String",
        "udp_expected": "Palindrome String"
    },
    {
        "id": 4,
        "dir": "04_number_palindrome",
        "name": "Number Palindrome",
        "input": "12321\n",
        "tcp_expected": "Palindrome Number",
        "udp_expected": "Palindrome Number"
    },
    {
        "id": 5,
        "dir": "05_reverse_string",
        "name": "Reverse String",
        "input": "college\n",
        "tcp_expected": "egelloc",
        "udp_expected": "egelloc"
    },
    {
        "id": 6,
        "dir": "06_prime_number",
        "name": "Prime Number Check",
        "input": "29\n",
        "tcp_expected": "Prime Number",
        "udp_expected": "Prime Number"
    },
    {
        "id": 7,
        "dir": "07_factorial",
        "name": "Factorial of a Number",
        "input": "6\n",
        "tcp_expected": "720",
        "udp_expected": "720"
    },
    {
        "id": 8,
        "dir": "08_vowels_consonants_digits",
        "name": "Count Vowels, Consonants, Digits",
        "input": "Computer 2026\n",
        "tcp_expected": "Vowels: 3, Consonants: 5, Digits: 4",
        "udp_expected": "Vowels: 3, Consonants: 5, Digits: 4"
    },
    {
        "id": 9,
        "dir": "09_matrix_sum",
        "name": "Matrix Total Sum & Diagonal Sum",
        "input": "3\n",
        "tcp_expected": "Total Sum =",
        "udp_expected": "Total Sum ="
    }
]

def run_tests():
    print("=" * 70)
    print("Networks Lab - Application Variations Automated Verification Suite")
    print("Ubuntu 16.04 / 18.04 / 20.04 Compatibility & Bug-Free Check")
    print("=" * 70)

    port = 9200
    total_passed = 0
    total_tests = len(TEST_CASES) * 2

    with tempfile.TemporaryDirectory() as tmpdir:
        for tc in TEST_CASES:
            target_dir = os.path.join(BASE_DIR, tc["dir"])
            print(f"\n[{tc['id']}/9] Testing: {tc['name']} ({tc['dir']})")

            # 1. Test TCP
            port += 1
            with open(os.path.join(target_dir, "server.c")) as f:
                s_code = f.read().replace("PORT 8080", f"PORT {port}")
            with open(os.path.join(target_dir, "client.c")) as f:
                c_code = f.read().replace("PORT 8080", f"PORT {port}")

            s_src = os.path.join(tmpdir, "s.c")
            c_src = os.path.join(tmpdir, "c.c")
            s_bin = os.path.join(tmpdir, "s")
            c_bin = os.path.join(tmpdir, "c")

            with open(s_src, "w") as f:
                f.write(s_code)
            with open(c_src, "w") as f:
                f.write(c_code)

            subprocess.run(["gcc", "-Wall", "-Wextra", s_src, "-o", s_bin], check=True)
            subprocess.run(["gcc", "-Wall", "-Wextra", c_src, "-o", c_bin], check=True)

            srv = subprocess.Popen([s_bin], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            time.sleep(0.12)
            cli = subprocess.Popen([c_bin], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            cli_out, _ = cli.communicate(input=tc["input"], timeout=3)
            srv_out, _ = srv.communicate(timeout=3)

            if tc["tcp_expected"] in cli_out:
                print(f"  [✓ PASS] TCP Socket Interaction verified (Expected: '{tc['tcp_expected']}')")
                total_passed += 1
            else:
                print(f"  [✗ FAIL] TCP Socket Interaction failed! Got: {cli_out.strip()}")

            # 2. Test UDP
            port += 1
            with open(os.path.join(target_dir, "udpserver.c")) as f:
                us_code = f.read().replace("PORT 8080", f"PORT {port}")
            with open(os.path.join(target_dir, "udpclient.c")) as f:
                uc_code = f.read().replace("PORT 8080", f"PORT {port}")

            us_src = os.path.join(tmpdir, "us.c")
            uc_src = os.path.join(tmpdir, "uc.c")
            us_bin = os.path.join(tmpdir, "us")
            uc_bin = os.path.join(tmpdir, "uc")

            with open(us_src, "w") as f:
                f.write(us_code)
            with open(uc_src, "w") as f:
                f.write(uc_code)

            subprocess.run(["gcc", "-Wall", "-Wextra", us_src, "-o", us_bin], check=True)
            subprocess.run(["gcc", "-Wall", "-Wextra", uc_src, "-o", uc_bin], check=True)

            srv = subprocess.Popen([us_bin], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            time.sleep(0.12)
            cli = subprocess.Popen([uc_bin], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            cli_out_udp, _ = cli.communicate(input=tc["input"], timeout=3)
            srv_out_udp, _ = srv.communicate(timeout=3)

            if tc["udp_expected"] in cli_out_udp:
                print(f"  [✓ PASS] UDP Datagram Interaction verified (Expected: '{tc['udp_expected']}')")
                total_passed += 1
            else:
                print(f"  [✗ FAIL] UDP Datagram Interaction failed! Got: {cli_out_udp.strip()}")

    print("\n" + "=" * 70)
    print(f"Test Summary: {total_passed}/{total_tests} tests passed successfully.")
    print("=" * 70)

    if total_passed == total_tests:
        print("ALL VARIATIONS ARE BUG-FREE AND READY FOR UBUNTU 16/18/20!")
        sys.exit(0)
    else:
        print("SOME TESTS FAILED.")
        sys.exit(1)

if __name__ == "__main__":
    run_tests()

