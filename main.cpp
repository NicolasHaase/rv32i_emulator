#include <iostream>
#include <bitset>

using namespace std;

#define TAM 12
#define SIZE 32


void type_identifier(int x) {
    int R_type_instruction = 0b000000110011, I_type_instruction = 0b000000010011, B_type_instruction = 0b000001100011, U_type_instruction = 0b000000110111, J_type_instruction = 0b000001101111;
    int aux = 0b000001111111;

    bitset<SIZE> respbin = x & aux;

    if (respbin == bitset<SIZE>(R_type_instruction)) cout << "Type R" << endl;
    if (respbin == bitset<SIZE>(I_type_instruction)) cout << "Type I" << endl;
    if (respbin == bitset<SIZE>(B_type_instruction)) cout << "Type B" << endl;
    if (respbin == bitset<SIZE>(U_type_instruction)) cout << "Type U" << endl;
    if (respbin == bitset<SIZE>(J_type_instruction)) cout << "Type J" << endl;
}

/** num_teste = 0b00000001111100000110111001110011
    R-Type Bit division = func7 = 1111111|rs2 = 11111|rs1 = 11111|func3 = 111|rd = 11111|opcode0110011
    I-Type Bit division = imm[11:0] = 111111111111|rs1 = 11111|func 3 = 111|rd = 11111|opcode = 0010011
    B-Type Bit division =
    U-Type Bit division =
    J-Type Bit division =
*/

void R_division(int x) {
    int rd    = (x >> 7)  & 0b11111;// ele pega o num direto e não compara com o num inteiro
    int funct3 = (x >> 12) & 0b111;
    int rs1   = (x >> 15) & 0b11111;
    int rs2   = (x >> 20) & 0b11111;
    int funct7 = (x >> 25) & 0b1111111;

    cout << "funct7: " << bitset<7>(funct7) << " (" << funct7 << ")" << endl;
    cout << "rs2:    " << bitset<5>(rs2)    << " (" << rs2 << ")" << endl;
    cout << "rs1:    " << bitset<5>(rs1)    << " (" << rs1 << ")" << endl;
    cout << "funct3: " << bitset<3>(funct3) << " (" << funct3 << ")" << endl;
    cout << "rd:     " << bitset<5>(rd)     << " (" << rd << ")" << endl;

    // Identificação da instrução específica
    if (funct3 == 0b000 && funct7 == 0b0000000)
        cout << "Instruction: ADD" << endl;
    else if (funct3 == 0b000 && funct7 == 0b0100000)
        cout << "Instruction: SUB" << endl;
    else if (funct3 == 0b111)
        cout << "Instruction: AND" << endl;
    else if (funct3 == 0b110)
        cout << "Instruction: OR" << endl;
    else if (funct3 == 0b100)
        cout << "Instruction: XOR" << endl;
    else
        cout << "Instruction: Unknown R-Type" << endl;
}

/**
INSTRUCTIONS - TIPO I

shamt
SLLI - 001 (00000)
SRLI - 101 (00000)
SRAI - 101 (01000)

ADDI - 000
XORI - 100
ORI - 110
ANDI - 111
SLTI - 010
SLTIU - 011

JALR - 000 (offset ao invés de imm) (opcode - 1100111)
FENCE - 000 (opcode - 0001111)
FENCE.I - 001 (opcode - 0001111)
ECALL - 000 (opcode - 1110011)
EBREAK - 000 (opcode - 1110011) (rs2[24:20] = 00001)
*/

void I_division(int x) {
    int rd    = (x >> 7)  & 0b11111;// ele pega o num direto e não compara com o num inteiro
    int funct3 = (x >> 12) & 0b111;
    int rs1   = (x >> 15) & 0b11111;
    int imm   = (x >> 20) & 0b111111111111;

    cout << "imm:    " << bitset<12>(imm)    << " (" << imm << ")" << endl;
    cout << "rs1:    " << bitset<5>(rs1)    << " (" << rs1 << ")" << endl;
    cout << "funct3: " << bitset<3>(funct3) << " (" << funct3 << ")" << endl;
    cout << "rd:     " << bitset<5>(rd)     << " (" << rd << ")" << endl;

    // Identificação da instrução específica
    if (funct3 == 0b000 && funct7 == 0b0000000)
        cout << "Instruction: ADD" << endl;
    else if (funct3 == 0b000 && funct7 == 0b0100000)
        cout << "Instruction: SUB" << endl;
    else if (funct3 == 0b111)
        cout << "Instruction: AND" << endl;
    else if (funct3 == 0b110)
        cout << "Instruction: OR" << endl;
    else if (funct3 == 0b100)
        cout << "Instruction: XOR" << endl;
    else
        cout << "Instruction: Unknown I-Type" << endl;
}

/**
INSTRUCTIONS - TIPO B

BEQ - 000
BNE - 001
BLT - 100
BGE - 101
BLTU - 110
BGEU - 111
*/

/**
INSTRUCTIONS - TIPO U

LUI - só tem imm, rd e opcode
AUIPC - só tem imm, rd e opcode
*/

/**
INSTRUCTIONS - TIPO J

JAL - tem 4 imm diferentes, rd e opcode
*/


int main() {
    int num1 = 0b00000001111100000110111001110011, num2 = 0b00000000000100001000000010010011, num3 = 0b000111100011, num4 = 0b100000110111, num5 = 0b011101101111;

    cout << "socorro\n";
    type_identifier(num2);
   
    R_division(num2);

    return 0;
}