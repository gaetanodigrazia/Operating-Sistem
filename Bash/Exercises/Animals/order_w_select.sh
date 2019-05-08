# DESCRIPTION : order animals.txt if not has been ordered, than select
# from 1 to 30 row and print it in a file called animals_ordered_select.txt.
# Select then row from 90 to 100 and append to it
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

if [ -f "animals_ordered.txt" ];
	then rm animals_ordered.txt
fi

if [ -f "animals_ordered_selected.txt" ];
	then rm animals_ordered_selected.txt
fi

if [ -f "animals_ordered.txt" ];
	then sed -n 1,30p < animals_ordered.txt > animals_ordered_selected.txt
	sed -n 90,100p < animals_ordered.txt >> animals_ordered_selected.txt
	exit 1
else
	sort < animals.txt > animals_ordered.txt;
	sed -n 1,30p < animals_ordered.txt > animals_ordered_selected.txt;
	sed -n 90,100p < animals_ordered.txt >> animals_ordered_selected.txt;
fi

