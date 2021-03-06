#!/bin/bash

#compile fbt to c

goFB -i=./fbt -o=./c -l=c -t=topFLAT
gcc ./c/*.c -o "./testgoFB_topFLAT.exe" -O1

# goFB -i=%WD%\fbt -o=%WD%\c -l=c -t=topFLAT -af 
# gcc ./examples/c/testgoFB/c/*.c -o ./examples/c/testgoFB/testgoFB_topFLAT_F.exe -O1

# goFB -i=%WD%\fbt -o=%WD%\c -l=c -t=topCFB1
# gcc ./examples/c/testgoFB/c/*.c -o ./examples/c/testgoFB/testgoFB_topCFB1.exe -O1

# goFB -i=%WD%\fbt -o=%WD%\c -l=c -t=topCFB1 -af
# gcc ./examples/c/testgoFB/c/*.c -o ./examples/c/testgoFB/testgoFB_topCFB1_F.exe -O1

# goFB -i=%WD%\fbt -o=%WD%\c -l=c -t=topMANY
# gcc ./examples/c/testgoFB/c/*.c -o ./examples/c/testgoFB/testgoFB_topMANY.exe -O1

# goFB -i=%WD%\fbt -o=%WD%\c -l=c -t=topMANY -af 
# gcc ./examples/c/testgoFB/c/*.c -o ./examples/c/testgoFB/testgoFB_topMANY_F.exe -O1
