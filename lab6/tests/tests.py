import pytest
from subprocess import STDOUT, check_output

program_under_test = './../cmake-build-debug/lab6'
program_args = []
second = 1
action_timeout = 10 * second


@pytest.mark.asyncio
async def test():
    cmd = [program_under_test]
    output = check_output(cmd, stderr=STDOUT, timeout=action_timeout)
    result = output.decode("utf-8")
    print("\nКонсольный вывод:")
    print(result)

    assert True
