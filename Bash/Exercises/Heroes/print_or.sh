# DESCRIPTION : print all heroes that match a pattern or
# another pattern
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

p1=$1
p2=$2
filename=$3

if [ $# -eq 0 ];
then echo "Insert 3 parameters"
elif [ $# -gt 3 ]
	then echo "Too much parameters, insert 3"
else
	grep -i -E "^($p1|$p2)" $filename
fi
