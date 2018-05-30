//-----------------------------LICENSE NOTICE------------------------------------
//  This file is part of CPCtelera: An Amstrad CPC Game Engine
//  Copyright (C) 2018 ronaldo / Fremos / Cheesetea / ByteRealms (@FranGallegoBR)
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//------------------------------------------------------------------------------

#include "menu.h"

void menu(){

	draw_menu();
	while (1){
		cpct_scanKeyboard();
		if(cpct_isKeyPressed(Key_1)){

			cpct_clearScreen_f64(0);
			break;
		
		}else if(cpct_isKeyPressed(Key_2)){

			reasign_buttons(); 
			draw_menu();
		
		}else if(cpct_isKeyPressed(Key_3)){

			show_credits();
			draw_menu();

			while(cpct_isAnyKeyPressed()){
				cpct_scanKeyboard();
			};

		}
	}
}

void draw_menu(){
	u8* pvmem;
	pvmem = cpct_getScreenPtr(CPCT_VMEM_START, 20, 20);
	cpct_drawStringM1("Welcome to CPCKetela!", pvmem, 1, 0);
	pvmem = cpct_getScreenPtr(CPCT_VMEM_START, 15, 55);
	cpct_drawStringM1("Press: ", pvmem, 1, 0);
	pvmem = cpct_getScreenPtr(CPCT_VMEM_START, 20, 70);
	cpct_drawStringM1("1: To play", pvmem, 1, 0);
	pvmem += 0x50 + 0x50;
	cpct_drawStringM1("2: Reasign buttons", pvmem, 1, 0);
	pvmem += 0x50 + 0x50;
	cpct_drawStringM1("3: Credits", pvmem, 1, 0);	
}

void fill_screen(u8 color){
	cpct_drawSolidBox((void*)0xC000, color, 64, 240);
}

void reasign_buttons(){

	u8* pvmem = cpct_getScreenPtr(CPCT_VMEM_START, 35, 100);;

	cpct_clearScreen_f64(0);

	cpct_drawStringM1("Up!", pvmem, 1, 0);
	waitReleaseKey(Key_2);
	keys.up = waitAKey();
	waitReleaseKey(keys.up);

	cpct_drawStringM1("Down!", pvmem, 1, 0);
	keys.down = waitAKey(); 
	waitReleaseKey(keys.down);

	cpct_drawStringM1("Left!", pvmem, 1, 0);
	keys.left = waitAKey(); 
	waitReleaseKey(keys.left);

	cpct_drawStringM1("Right!", pvmem, 1, 0);
	keys.right = waitAKey(); 
	waitReleaseKey(keys.right);
	
	cpct_drawStringM1("Shot! ", pvmem, 1, 0);
	keys.shot = waitAKey(); 
	waitReleaseKey(keys.shot);
	
	cpct_drawStringM1("Menu!", pvmem, 1, 0);
	keys.menu = waitAKey(); 
	waitReleaseKey(keys.menu);

	cpct_clearScreen_f64(0);
}

void show_credits(){

	u8* pvmem = cpct_getScreenPtr(CPCT_VMEM_START, 18, 60);
	
	cpct_clearScreen_f64(0);

	cpct_drawStringM1("Robert Esclapez Garcia", pvmem, 1, 0);
	pvmem = cpct_getScreenPtr(CPCT_VMEM_START, 38, 80);
	cpct_drawStringM1("&", pvmem, 1, 0);
	pvmem = cpct_getScreenPtr(CPCT_VMEM_START, 18, 100);
	cpct_drawStringM1("Jesus Perales Hernandez", pvmem, 1, 0);

	waitReleaseKey(Key_3);

	waitAKey();
	cpct_clearScreen_f64(0);
}