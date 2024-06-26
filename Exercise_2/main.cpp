#include <iostream>
#include <iomanip>
#include <bitset>


int main(){

    const int COLUMN_WIDTH {20};

    // Highlight position for bit of intereset with a 1
    // Mask other positions with 0
    
    const unsigned char mask_bit_0 {0b00000001}; // Bit0
    const unsigned char mask_bit_1 {0b00000010}; // Bit1
    const unsigned char mask_bit_2 {0b00000100}; // Bit2
    const unsigned char mask_bit_3 {0b00001000}; // Bit3
    const unsigned char mask_bit_4 {0b00010000}; // Bit4
    const unsigned char mask_bit_5 {0b00100000}; // Bit5
    const unsigned char mask_bit_6 {0b01000000}; // Bit6
    const unsigned char mask_bit_7 {0b10000000}; // Bit7

    // Variable
    unsigned char var {0b00000000};

    std::cout << std::setw(COLUMN_WIDTH) << "var : " 
              << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;

    //Set a few bits: make them 1's regardless of what's in there
    // Set bit 1
    std::cout << "Setting bit in position 1 " << std::endl;
    var |= mask_bit_1;
    std::cout << std::setw(COLUMN_WIDTH) << "var : " 
              << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;
   
    // Set bit 5
    std::cout << "Setting bit in position 5 " << std::endl;
    var |= mask_bit_5;
    std::cout << std::setw(COLUMN_WIDTH) << "var : " 
              << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;

    // Resetting bits: set tp 0
    // Resetting : &(~mask)
    std::cout << "Resetting bit in position 1 " << std::endl;
    var &= static_cast<unsigned char>(~mask_bit_1);
    std::cout << std::setw(COLUMN_WIDTH) << "var : " 
              << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;

    // Set all bits
    std::cout << "Setting bit in position 5 " << std::endl;
    var |= (mask_bit_0 | mask_bit_2 | mask_bit_4 | mask_bit_6);
    std::cout << std::setw(COLUMN_WIDTH) << "var : " 
              << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;

    // checking state of a bit
    std::cout << "Checking the state of each bit position (on/off) " << std::endl;
    std::cout << "bit0 is " << ((var & mask_bit_0) >> 0) << std::endl;
    std::cout << "bit1 is " << ((var & mask_bit_1) >> 1) << std::endl;
    std::cout << "bit2 is " << ((var & mask_bit_2) >> 2) << std::endl;
    std::cout << "bit3 is " << ((var & mask_bit_3) >> 3) << std::endl;
    std::cout << "bit4 is " << ((var & mask_bit_4) >> 4) << std::endl;
    std::cout << "bit5 is " << ((var & mask_bit_5) >> 5) << std::endl;
    std::cout << "bit6 is " << ((var & mask_bit_6) >> 6) << std::endl;
    std::cout << "bit7 is " << ((var & mask_bit_7) >> 7) << std::endl;
    std::cout << std::boolalpha;
    std::cout << "bit6 is " << static_cast<bool>(var & mask_bit_6) << std::endl; 


    // Toggle bits
    // Toggle : var ^ mask 
    std::cout << std::endl;
    std::cout << "Toggle bit 0" << std::endl;
    var ^= mask_bit_0;
    std::cout << std::setw(COLUMN_WIDTH) << "var : " 
              << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;

    return 0;
}
