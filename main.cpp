#include <iostream>
#include <bitset>

using namespace std;

#define SIZE 32

int type_identifier(int x);
void R_division(int x);
void I_division(int x);
void S_division(int x);
void B_division(int x);
void U_division(int x);
void J_division(int x);

int type_identifier(int x) {
    int opcode = x & 0b1111111;
    cout << "Opcode: " << bitset<7>(opcode) << " (" << opcode << ")" << endl;

    switch (opcode) {
        case 0b0110011:
            cout << "Type R " << endl;
            return 'R';
        case 0b0010011:
            cout << "Type I " << endl;
        case 0b1100111:
            cout << "Type I " << endl;
        case 0b0001111:
            cout << "Type I " << endl;
        case 0b1110011:
            cout << "Type I " << endl;


        case 0b0100011:
            cout << "Type S (Store instructions)" << endl;
            return 'S';
        case 0b1100011:
            cout << "Type B (Branch instructions)" << endl;
            return 'B';
        case 0b0110111:


            cout << "Type U" << endl;
            return 'U';
        case 0b0010111:
            cout << "Type U" << endl;
            return 'U';
        case 0b1101111:
            cout << "Type J (JAL)" << endl;
            return 'J';
        default:
            cout << "Instrução desconhecida" << endl;
            return '?';// coloquei ? para apenas não entrar na func de Instrução
    }
}

// --------------------- R-Type --------------------- (FEITO)
void R_division(int x) {
    int rd    = (x >> 7)  & 0b11111;
    int funct3 = (x >> 12) & 0b111;
    int rs1   = (x >> 15) & 0b11111;
    int rs2   = (x >> 20) & 0b11111;
    int shamt = (x >> 25) & 0b11;
    int funct7 = (x >> 27) & 0b11111;

    cout << "\n=== R-Type camadas ===\n";
    cout << "funct7: " << bitset<5>(funct7) << " (" << funct7 << ")\n";
    cout << "shamt:  " << bitset<2>(shamt)  << " (" << shamt << ")\n";
    cout << "rs2:    " << bitset<5>(rs2)    << " (" << rs2 << ")\n";
    cout << "rs1:    " << bitset<5>(rs1)    << " (" << rs1 << ")\n";
    cout << "funct3: " << bitset<3>(funct3) << " (" << funct3 << ")\n";
    cout << "rd:     " << bitset<5>(rd)     << " (" << rd << ")\n";

    if (funct3 == 0b001 && funct7 == 0b00000)
        cout << "Instruction: SLL" << endl;
    if (funct3 == 0b101 && funct7 == 0b00000)
        cout << "Instruction: SRL" << endl;
    if (funct3 == 0b101 && funct7 == 0b01000)
        cout << "Instruction: SRA" << endl;
    if (funct3 == 0b000 && funct7 == 0b00000)
        cout << "Instruction: ADD" << endl;
    if (funct3 == 0b000 && funct7 == 0b01000)
        cout << "Instruction: SUB" << endl;
    if (funct3 == 0b100 && funct7 == 0b00000)
        cout << "Instruction: XOR" << endl;
    if (funct3 == 0b110 && funct7 == 0b00000)
        cout << "Instruction: OR" << endl;
    if (funct3 == 0b111 && funct7 == 0b00000)
        cout << "Instruction: AND" << endl;
    if (funct3 == 0b010 && funct7 == 0b00000)
        cout << "Instruction: SLT" << endl;
    if (funct3 == 0b011 && funct7 == 0b00000)
        cout << "Instruction: SLTU" << endl;
}

// --------------------- I-Type --------------------- (N FEITO)
void I_division(int x) {
    int rd    = (x >> 7)  & 0b11111;
    int funct3 = (x >> 12) & 0b111;
    int rs1   = (x >> 15) & 0b11111;
    int shamt = (x >> 20) & 0b11111;
    int bits  = (x >> 25) & 0b11;
    int funct7 = (x >> 27) & 0b11111;
    int imm   = (x >> 20) & 0b11111111111111111111;

    cout << "\n=== I-Type camadas ===\n";
    cout << "imm:       " << bitset<12>(imm) << " (" << imm << ")\n";
    cout << "funct7:    " << bitset<5>(funct7)    << " (" << funct7 << ")\n";
    cout << "bits:   " << bitset<2>(bits)   << " (" << bits << ")\n";
    cout << "shamt:  " << bitset<5>(shamt)  << " (" << shamt << ")\n";
    cout << "rs1:    " << bitset<5>(rs1)    << " (" << rs1 << ")\n";
    cout << "funct3: " << bitset<3>(funct3) << " (" << funct3 << ")\n";
    cout << "rd:     " << bitset<5>(rd)     << " (" << rd << ")\n";

    if (funct3 == 0b000) cout << "Instruction: ADDI\n";
    else if (funct3 == 0b010) cout << "Instruction: SLTI\n";
    else if (funct3 == 0b111) cout << "Instruction: ANDI\n";
    else if (funct3 == 0b110) cout << "Instruction: ORI\n";
    else if (funct3 == 0b100) cout << "Instruction: XORI\n";
    else cout << "Instruction: desconhecida I-Type\n";
}

// --------------------- S-Type --------------------- (N PRECISA)
void S_division(int x) {
    int imm4_0 = (x >> 7) & 0b11111;
    int funct3 = (x >> 12) & 0b111;
    int rs1 = (x >> 15) & 0b11111;
    int rs2 = (x >> 20) & 0b11111;
    int imm11_5 = (x >> 25) & 0b1111111;
    int imm = (imm11_5 << 5) | imm4_0;

    cout << "\n=== S-Type camadas ===\n";
    cout << "imm:    " << bitset<12>(imm) << " (" << imm << ")\n";
    cout << "rs2:    " << bitset<5>(rs2) << " (" << rs2 << ")\n";
    cout << "rs1:    " << bitset<5>(rs1) << " (" << rs1 << ")\n";
    cout << "funct3: " << bitset<3>(funct3) << " (" << funct3 << ")\n";

    if (funct3 == 0b010) cout << "Instruction: SW\n";
    else if (funct3 == 0b000) cout << "Instruction: SB\n";
    else if (funct3 == 0b001) cout << "Instruction: SH\n";
    else cout << "Instruction: desconhecida S-Type\n";
}

// --------------------- B-Type ---------------------
void B_division(int x) {
    int imm11 = (x >> 7) & 0b1;
    int imm4_1 = (x >> 8) & 0b1111;
    int funct3 = (x >> 12) & 0b111;
    int rs1 = (x >> 15) & 0b11111;
    int rs2 = (x >> 20) & 0b11111;
    int imm10_5 = (x >> 25) & 0b111111;
    int imm12 = (x >> 31) & 0b1;
    int imm = (imm12 << 12) | (imm11 << 11) | (imm10_5 << 5) | (imm4_1 << 1);

    cout << "\n=== B-Type camadas ===\n";
    cout << "imm:    " << bitset<13>(imm) << " (" << imm << ")\n";
    cout << "rs2:    " << bitset<5>(rs2) << " (" << rs2 << ")\n";
    cout << "rs1:    " << bitset<5>(rs1) << " (" << rs1 << ")\n";
    cout << "funct3: " << bitset<3>(funct3) << " (" << funct3 << ")\n";

    if (funct3 == 0b000) cout << "Instruction: BEQ\n";
    else if (funct3 == 0b001) cout << "Instruction: BNE\n";
    else if (funct3 == 0b100) cout << "Instruction: BLT\n";
    else if (funct3 == 0b101) cout << "Instruction: BGE\n";
    else cout << "Instruction: desconhecida B-Type\n";
}

// --------------------- U-Type --------------------- (FEITO)
void U_division(int x) {
    int opcode = (x >> 0) & 0b1111111;
    int rd = (x >> 7) & 0b11111;
    int imm = (x >> 25) &0b1111111111111111111111111;

    cout << "\n=== U-Type camadas ===\n";
    cout << "imm[31:12]: " << bitset<25>(imm) << " (" << imm << ")\n";
    cout << "rd:         " << bitset<5>(rd) << " (" << rd << ")\n";

    if (opcode == 0b0110111)
        cout << "Instruction: LUI" << endl;
    if (opcode == 0b0010111)
        cout << "Instruction: AUIPC" << endl;
}

// --------------------- J-Type --------------------- (FEITO)
void J_division(int x) {
    int rd = (x >> 7) & 0b11111;
    int imm19_12 = (x >> 8) & 0b11111111;
    int imm11 = (x >> 1) & 0b1;
    int imm10_1 = (x >> 10) & 0b1111111111;
    int imm20 = (x >> 1) & 0b1;

    cout << "\n=== J-Type camadas ===\n";
    cout << "imm20: " << bitset<1>(imm20) << " (" << imm20 << ")\n";
    cout << "imm10_1: " << bitset<10>(imm10_1) << " (" << imm10_1 << ")\n";
    cout << "imm11: " << bitset<1>(imm11) << " (" << imm11 << ")\n";
    cout << "imm19_12: " << bitset<8>(imm19_12) << " (" << imm19_12 << ")\n";
    cout << "rd:  " << bitset<5>(rd) << " (" << rd << ")\n";
    cout << "Instruction: JAL\n";
}


int main() {
    /**
    int num0 = 0b00000001111100000110111001110011, //   erro
        num1 = 0b00000000001100010000000010110011, // R-type
        num2 = 0b00000000000100000000000010010011, // I-type (ADDI)
        num3 = 0b00000000001000001000000100100011, // S-type (SW)
        num4 = 0b00000000000100000000000001100011, // B-type (BEQ)
        num5 = 0b00000000000000000001000010110111; // U-type (LUI)

    int instruction = num5; // você pode trocar para testar os outros
    int type = type_identifier(instruction);

    switch (type) {
        case 'R': R_division(instruction); break;
        case 'I': I_division(instruction); break;
        case 'S': S_division(instruction); break;
        case 'B': B_division(instruction); break;
        case 'U': U_division(instruction); break;
        case 'J': J_division(instruction); break;
        default: cout << "Tipo não reconhecido." << endl;
    }
    */

    int num1 = 0b00000001100000000000001101101111, num2 = 0b11100000000001100000000001101111;

    cout << "\n\n1o Instruction:\n" ;
    J_division(num1);
    cout << "\n\n";
    cout << "\n\n2o Instruction:\n" ;
    J_division(num2);


    return 0;
}