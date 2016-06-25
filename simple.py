#
#   Kako uporabljat ... poženi program, ta te vpraša po številki problema, ki ga rešuješ (=st problema na strani project euler)
#   program pa avtomatsko naredi mapo Problem_st_problema in v mapi datoteko aaa.c, ki naj bi vsebovala pravilna navodila in 
#   in še nekaj malenkosti v c-ju kot so includi printf-i ...
#

#   Run with Python3 not 2!!
import os
import errno
import io
import urllib.request
import re

# Stevilka problema za katerega ustvarimo mapo & file
num = input("Vnesi stevilko problema :")

# Kreiranje imena direktorija
newpath = r'Problem_'+num
site_name = 'https://projecteuler.net/problem='+num

# Prenos html.dat s katere bomo prebrali navodila problema
response = urllib.request.urlopen(site_name)
html = response.read()
# Parsanje spremenljivke html  ---- če je tekst preveč "naličen" nedeluje 100%
problem_html = html.decode('utf8').split('<div class="problem_content" role="problem">')[1].split('<div class="noprint" style="text-align:center;"></div>')[0].split("</div><br />")[0].replace("<br />", "\n").replace("<p>", "").replace("</p>", "\n")

# Kreiranje komentarjev ki, jih bomo zapisali v aaa.c 
file_write_comment = "/*\nPROBLEM "+num+"\n"+problem_html+"\n*/"
file_write_main = "\n\n#include <stdio.h>\n#include <stdlib.h>\n\nint main()\n{\n    int res = 0;\n\n    printf();\n\n    return 0;\n}\n"

# Preverjanje če ta obstaja 
if not os.path.exists(newpath):
    # Dir še ne obstaja ga kreiramo
    os.makedirs(newpath)
    print("Succesfuly created /"+newpath)
    # Odpiranje datoteke v mapi(newpath)
    file = open(newpath+"/aaa.c", "w")
    # Pisanje osnove v file
    file.write(file_write_comment+file_write_main)
    
else:
    print("Directory /"+newpath+" already exists!")
    
    