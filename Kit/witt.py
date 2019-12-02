# -*- coding: utf-8 -*-

import argparse

def get_bit_str(rawbit):
        
        if rawbit == b'':
           return "."
        else:
           
            num_bit = int.from_bytes(rawbit,"big")
            if rawbit.isascii() and num_bit >  0x1F and num_bit != 0x7F:
                return rawbit.decode("ascii")
            else:
                return "_"


parser = argparse.ArgumentParser()
parser.add_argument("filename",help="文件名")
parser.add_argument("-l", help="显示字节数,10进制",
                    type=int,default=0x666)
parser.add_argument("-o", help="偏移量",
                    type=int,default=0)
args = parser.parse_args()


f = open(args.filename,'rb')
width = 16
f.seek(args.o,0)
count = args.o
rawbit = f.read(1)
tmps = ""
while rawbit != b'' and count <= args.o+args.l:
    
    print(f"{count:#08x}",end='    ')
    for x in range(width):
        bit = rawbit.hex()
        if bit != '':
            print(bit,end=' ')
        else:
            print("  ",end=' ')
        tmps += get_bit_str(rawbit)
        rawbit = f.read(1)

    count += width    
    print(" |",end="  ")
    print(tmps)
    tmps = ""
    
f.close()