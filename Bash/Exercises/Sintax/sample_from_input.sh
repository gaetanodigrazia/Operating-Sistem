# DESCRIPTION : take a value from input and filter it with case
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
value=$1

echo "Choice: audi, fiat, bmw"



if [ $# -eq 0 ]
then
	echo "Value inserted: none"
	echo "No arguments supplied"
else
	echo "Value inserted: $value"
	case $value in
		( ferrari )
		echo "It cost 300000000";;
		( fiat )
		echo "It cost 20";;
		( bmw )
		echo "5000";;
		( * )
		echo "I don't know this car"
	esac	
fi

