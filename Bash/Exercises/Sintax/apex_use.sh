# DESCRIPTION : difference between apex
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
data=`date +%d/%m/%Y`
echo "1 - Oggi e’ il $data."

data= "date +%d/%m/%Y"
echo "2 - Oggi e’ il $data."

data='date +%d/%m/%Y'
echo "3 - Oggi e’ il $data."

echo "4 - Oggi e’ il `date +%d/%m/%Y`."

echo "5 - Oggi e’ il $(date +%d/%m/%Y)."

echo "Per stampare una parola chiava bisogna anteporre il backslash \\"

echo "Quindi \" Lascia che il backtick e il \$ siano interpretati"
 
echo "Backtick \` serve per operazioni"

echo " ' stampa soltanto, senza interpretare nulla"