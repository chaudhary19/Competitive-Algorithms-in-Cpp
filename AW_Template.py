import atexit, io, sys

buffer = io.BytesIO()
sys.stdout = buffer

@atexit.register
def write(): sys.__stdout__.write(buffer.getvalue())
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_string(): return sys.stdin.readline().strip()
