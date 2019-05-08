# DESCRIPTION : awk usage
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
# 
# Copyright (c) 2019 by Gaetano Di Grazia, education.digrazia@gmail.com
# All rights reserved.

#!/bin/bash

echo "Insert a filename: "
read filename

#PRINT THE FIRST COLUMN OF EVERY LINE OF $FILENAME
awk '{print $1}' $filename

#PRINT THE FIRST AND SECOND WORD
awk '{print $1, $2}' $filename

#PRINT ALL THE LINE
awk '{print $0}' $filename

#PRINT LAST COLUMN OF THE LINE
awk '{print $NF}' $filename

#PRINT ALL THE LINE THAT MATCH A PATTERN
awk '/pattern/' $filename

#PRINT ALL THE LINE THAT BEGIN WITH A PATTERN
awk '/^pattern/' $filename

#PRINT ALL THE LINE THAT END WITH A PATTERN
awk '/pattern$/' $filename

#PRINT EVERY LINE THAT CONTAINS NUMBER
awk '/[0-9]/' $filename

#PRINT EVERY LINE CONTAINS A LOWERCASE LETTER
awk '/[a-z]/' $filename

#PRINT EVERY LINE THAT CONTAINS AT LEAST 1 O OR MORE
awk '/hel+o/' $filename
#or
awk '/hel[0]{1,}/' $filename

#PRINT EVERY LINE THAT CONTAIN ABC OR 123
awk '/abc|123/' $filename

#PRINT THE LINE NUMBER OF EVERY LINE OF THE FILE
awk '{print $NR}' $filename

#PRINT THE LIBRARY NAME OF A SAMPLE C PROGRAM
awk -F '<|>' '/^#/ {print $2}' $filename

#PRINT THE LIBRARY NAME OF A SAMPLE C PROGRAM
awk -F '<|>' '/^#/ {print $2}' $filename

#PRINT #PRINT THE LIBRARY NAME OF A SAMPLE C PROGRAM IN UNIQUE
awk -F '<|>' '/^# {print $2}' $filename | sort | uniq


#AWK VARIABLES
#FS = INPUT FIELD SEPARATOR VALUE
#OFS = OUTPUT FIELD SEPARATOR VALUE
#NF = NUMBER OF FIELDS ON THE CURRENT LINE
#NR = NUMBER OF RECORDS IN THE CURRENT FILE
#RS = RECORD SEPARATOR VALUE
#ORS = OUTPUT RECORD SEPARATOR
#FILENAME = CURRENT FILE NAME BEING PROCESSED
#
#
#
# Regex command
# ? the item is matched 0 or 1 times
# * the item is matched 0 or n times
# + the item is matched 1 or n times
# . the item is matched 1 times
# {n} the items is matched exactly n times
# {n, } the item is matched n or more times
# {, m} the item is matched at most m times
# {n,m} the item is matched from n to m times
# $ the item is matched at the end of the pattern
# ^ the item is matched at the beginning of the pattern
# [A-Z] the item match one of this uppercase letter (A to Z)
# [a-z] the item match one of this lowercase letter (a to z)
# [0-9] the item match one of this number (0 to 9)
# (abc|def) match the first or the second pattern
# It is possible to combine expression like:
# [A-Z0-9] search for an alphanumeric
# (abc|def)+ at least one of abc or def is matched