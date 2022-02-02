/**
 * @file main.cpp
 * @author Rohit Patil (rpatil10@umd.edu)
 * @brief RWA-1 Program Flow Control and Functions
 * @version 0.1
 * @date 2021-09-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

using namespace std;

/*
define your data structures here
*/

/**
 * @brief structure for number of boxes available of each type
 * 
 */

struct BoxNumbers{
	unsigned int s{}; //Number of boxes available of size small
	unsigned int m{}; //Number of boxes available of size medium
	unsigned int l{}; //Number of boxes available of size large
	unsigned int xl{}; //Number of boxes available of size extra large
};

/**
 * @brief structure for maximum number of parts that each box type can hold
 * 
 */

struct PartsPerBox{
	unsigned int s_max_parts{}; //Maximum number of parts a small box can hold
	unsigned int m_max_parts{}; //Maximum number of parts a medium box can hold
	unsigned int l_max_parts{}; //Maximum number of parts a large box can hold
	unsigned int xl_max_parts{}; //Maximum number of parts an extra large box can hold
};

BoxNumbers box_types_and_number; //global variable for BoxNumber structure
PartsPerBox max_parts_by_each_boxes;  //global variable for PartsPerBox structure
int total_parts;  // global variable for total parts available

/*
function prototypes here
*/

unsigned int get_total_parts();
void get_total_boxes(BoxNumbers& boxes);
void get_part_per_box(PartsPerBox& maxPartPerBox);
void fill_up_boxes(const BoxNumbers& boxes, const PartsPerBox& maxPartPerBox, int totalParts);


/*
function definitions here
*/

/**
 * @brief Get the total number of parts to be placed in boxes
 * @return unsigned Number of parts entered by the user
 */

unsigned int get_total_parts(){
	int t;
	while(std::cout << "How many parts in total?: " && (!(std::cin >> t) || t<=0)){
		std::cout << "Please enter a positive integer!" << "\n";
        std::cin.clear();
	} //Reads user input and prompts user repeatedly to enter a new number until a positive integer is entered
	return t;
}

/**
 * @brief Get the total number of boxes for each type
 * 
 * @param boxes 
 */

void get_total_boxes(BoxNumbers& boxes){
	int s,m,l,xl;
	while(std::cout << "How many boxes for S/M/L/XL?: " && (!(std::cin >> s >> m >> l >> xl) || s<=0 || m<=0 || l<=0 || xl<=0)){
		std::cout << "Please enter a positive integer!" << "\n";
        std::cin.clear();
	}  //Reads user input and prompts user repeatedly to enter a new set of numbers until a positive integers is entered
	boxes.s = s;
	boxes.m = m;
	boxes.l = l;
	boxes.xl = xl;
	// saves total number of boxes are available of each type in structure variable
}

/**
 * @brief Get the number of parts for each box type
 * 
 * @param maxPartPerBox 
 */

void get_part_per_box(PartsPerBox& maxPartPerBox){
	int s,m,l,xl;
	while(std::cout << "How many parts per box for S/M/L/XL?: " && (!(std::cin >> s >> m >> l >> xl) || s<=0 || m<=0 || l<=0 || xl<=0 || s>=m || m>=l || l>=xl)){
		std::cout << "Please enter a positive integer and ascending order of parts capacity! S<M<L<XL" << "\n";
        std::cin.clear();
	}  //Reads user input and prompts user repeatedly to enter set of new numbers until a positive integers is entered and to check condition S<M<L<XL
	maxPartPerBox.s_max_parts = s;
	maxPartPerBox.m_max_parts = m;
	maxPartPerBox.l_max_parts = l;
	maxPartPerBox.xl_max_parts = xl;
	// saves maximum number of parts each type of box can hold in structure variable
}

/**
 * @brief Fill up boxes from user inputs
 * 
 * @param boxes 
 * @param maxPartPerBox 
 * @param totalParts 
 */

void fill_up_boxes(const BoxNumbers& boxes, const PartsPerBox& maxPartPerBox, int totalParts){
	std::cout << "\n" << "Boxes that can be built with: " << totalParts << " parts" << "\n";
	std::cout << "----------------------------------------" << "\n";
	// Computes number of XL size box that can be used on given condition
	if(totalParts/(maxPartPerBox.xl_max_parts)>=1){
		int i = boxes.xl;
		for(i;i>=1;i--){
			if(totalParts/(i*maxPartPerBox.xl_max_parts)>=1)
				break;
		}
		totalParts -= i*maxPartPerBox.xl_max_parts;
		std::cout << "XL box (" << boxes.xl << " " << "x" << " " << maxPartPerBox.xl_max_parts << "):" << i << "--" << " " << "remaining parts:" << totalParts <<"\n";
	}

	// Computes number of L size box that can be used on given condition
	if(totalParts/(maxPartPerBox.l_max_parts)>=1){
		int i = boxes.l;
		for(i;i>=1;i--){
			if(totalParts/(i*maxPartPerBox.l_max_parts)>=1)
				break;
		}
		totalParts -= i*maxPartPerBox.l_max_parts;
		std::cout << "L box (" << boxes.l << " " << "x" << " " << maxPartPerBox.l_max_parts << "):" << i << "--" << " " << "remaining parts:" << totalParts << "\n";
	}

	// Computes number of M size box that can be used on given condition
	if(totalParts/(maxPartPerBox.m_max_parts)>=1){
		int i = boxes.m;
		for(i;i>=1;i--){
			if(totalParts/(i*maxPartPerBox.m_max_parts)>=1)
				break;
		}
		totalParts -= i*maxPartPerBox.m_max_parts;
		std::cout << "M box (" << boxes.m << " " << "x" << " " << maxPartPerBox.m_max_parts << "):" << i << "--" << " " << "remaining parts:" << totalParts << "\n";
	}

	// Computes number of S size box that can be used on given condition
	if(totalParts/(maxPartPerBox.s_max_parts)>=1){
		int i = boxes.s;
		for(i;i>=1;i--){
			if(totalParts/(i*maxPartPerBox.s_max_parts)>=1)
				break;
		}
		totalParts -= i*maxPartPerBox.s_max_parts;
		std::cout << "S box (" << boxes.s << " " << "x" << " " << maxPartPerBox.s_max_parts << "):" << i << "--" << " " << "remaining parts:" << totalParts << "\n";
	}
	//Displays number of parts that could not be fit in any boxes on given condition
	std::cout << "Parts not in boxes: "<< totalParts << "\n";
}

/**
 * @brief main function
 * 
 * @return int 
 */

int main()
{
	total_parts = get_total_parts(); //Get the total number of parts to be placed in boxes
	get_total_boxes(box_types_and_number); //Get the total number of boxes for each type
	get_part_per_box(max_parts_by_each_boxes); //Get the maximun number of parts for each box type
	fill_up_boxes(box_types_and_number,max_parts_by_each_boxes,total_parts); //Compute and fill up boxes from user inputs
}