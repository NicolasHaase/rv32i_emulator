#include <iostream>
#include <bitset>

using namespace std;

#define SIZE 32

int get_opcode(int x) {
    int n = (x >> 0) & 0b1111111;
    return n;
}
int get_rd(int x) {
    int n = (x >> 7) & 0b11111;
    return n;
}
int get_funct3(int x) {
    int n = (x >> 12) & 0b111;
    return n;
}
int get_rs1(int x) {
    int n = (x >> 15) & 0b11111;
    return n;
}
int get_rs2(int x) {
    int n = (x >> 20) & 0b11111;
    return n;
}
int get_shamt(int x) {
    int n = (x >> 25) & 0b11;
    return n;
}
int get_funct7(int x) {
    int n = (x >> 27) & 0b11111;
    return n;
}
int get_succ(int x) {
    int n = (x >> 20) & 0b1111;
    return n;
}
int get_pred(int x) {
    int n = (x >> 24) & 0b1111;
    return n;
}
int get_fence_end(int x) {
    int n = (x >> 28) & 0b1111;
    return n;
}
int get_imm(int x) {
    int n = (x >> 20) & 0b111111111111;
    return n;
}
int get_shamt_I(int x) {
    int n = (x >> 20) & 0b11111;
    return n;
}
int get_bits(int x) {
    int n = (x >> 25) & 0b11;
    return n;
}
int get_imm11(int x) {
    int n = (x >> 7) & 0b1;
    return n;
}
int get_imm4_1(int x) {
    int n = (x >> 8) & 0b1111;
    return n;
}
int get_imm10_5(int x) {
    int n = (x >> 25) & 0b11;
    return n;
}
int get_imm12(int x) {
    int n = (x >> 27) & 0b11111;
    return n;
}
int get_imm19_12(int x) {
    int n = (x >> 12) & 0b11111111;
    return n;
}
int get_imm11_J(int x) {
    int n = (x >> 20) & 0b1111;
    return n;
}
int get_imm10_1(int x) {
    int n = (x >> 25) & 0b11;
    return n;
}
int get_imm20(int x) {
    int n = (x >> 27) & 0b11111;
    return n;
}

char type_identifier(int x) {
    switch (get_opcode(x)) {
        case 0b0110011:
            return 'R';
        case 0b0010011:
            return 'I';
        case 0b1100111:
            return 'I';
        case 0b0001111:
            return 'I';
        case 0b1110011:
            return 'I';
        case 0b0100011:
            return 'S';
        case 0b1100011:
            return 'B';
        case 0b0110111:
            return 'U';
        case 0b0010111:
            return 'U';
        case 0b1101111:
            return 'J';
        default:
            cout << "Instrução desconhecida" << endl;
            return '?';// coloquei ? para apenas não entrar na func de Instrução
    }
}

// --------------------- R-Type --------------------- (FEITO)
void R_division(int x) {

    cout << "\n=== R-Type camadas ===\n";
    cout << "funct7: " << bitset<5>(get_funct7(x)) << " (" << get_funct7(x) << ")\n";
    cout << "shamt:  " << bitset<2>(get_shamt(x))  << " (" << get_shamt(x) << ")\n";
    cout << "rs2:    " << bitset<5>(get_rs2(x))    << " (" << get_rs2(x) << ")\n";
    cout << "rs1:    " << bitset<5>(get_rs1(x))    << " (" << get_rs1(x) << ")\n";
    cout << "funct3: " << bitset<3>(get_funct3(x)) << " (" << get_funct3(x) << ")\n";
    cout << "rd:     " << bitset<5>(get_rd(x))     << " (" << get_rd(x) << ")\n";

    int n1 = get_funct3(x), n2 = get_funct7(x);

    if (n1 == 0b001 && n2 == 0b00000)
        cout << "Instruction: SLL" << endl;
    if (n1 == 0b101 && n2 == 0b00000)
        cout << "Instruction: SRL" << endl;
    if (n1 == 0b101 && n2 == 0b01000)
        cout << "Instruction: SRA" << endl;
    if (n1 == 0b000 && n2 == 0b00000)
        cout << "Instruction: ADD" << endl;
    if (n1 == 0b000 && n2 == 0b01000)
        cout << "Instruction: SUB" << endl;
    if (n1 == 0b100 && n2 == 0b00000)
        cout << "Instruction: XOR" << endl;
    if (n1 == 0b110 && n2 == 0b00000)
        cout << "Instruction: OR" << endl;
    if (n1 == 0b111 && n2 == 0b00000)
        cout << "Instruction: AND" << endl;
    if (n1 == 0b010 && n2 == 0b00000)
        cout << "Instruction: SLT" << endl;
    if (n1 == 0b011 && n2 == 0b00000)
        cout << "Instruction: SLTU" << endl;
}

// --------------------- I-Type --------------------- (FEITO)
void I_division(int x) {

    cout << "\n=== I-Type camadas ===\n";
    if (get_opcode(x) == 0b0010011 && (get_funct3(x) == 0b001 || get_funct3(x) == 0b101)) {
        cout << "funct7: " << bitset<5>(get_funct7(x)) << " (" << get_funct7(x) << ")\n";
        cout << "bits:   " << bitset<2>(get_bits(x)) << " (" << get_bits(x) << ")\n";
        cout << "shamt:  " << bitset<5>(get_shamt(x)) << " (" << get_shamt(x) << ")\n";
        cout << "rs1:    " << bitset<5>(get_rs1(x)) << " (" << get_rs1(x) << ")\n";
        cout << "funct3: " << bitset<3>(get_funct3(x)) << " (" << get_funct3(x) << ")\n";
        cout << "rd:     " << bitset<5>(get_rd(x)) << " (" << get_rd(x) << ")\n";

        if (get_funct3(x) == 0b001 && get_funct7(x) == 0b00000) cout << "Instruction: SLLI\n";
        if (get_funct3(x) == 0b101 && get_funct7(x) == 0b00000) cout << "Instruction: SRLI\n";
        if (get_funct3(x) == 0b101 && get_funct7(x) == 0b01000) cout << "Instruction: SRAI\n";
    }
    if (get_opcode(x) == 0b0010011 && get_funct3(x) != 0b001 && get_funct3(x) != 0b101) {
        cout << "imm:    " << bitset<20>(get_imm(x)) << " (" << get_imm(x) << ")\n";
        cout << "rs1:    " << bitset<5>(get_rs1(x)) << " (" << get_rs1(x) << ")\n";
        cout << "funct3: " << bitset<3>(get_funct3(x)) << " (" << get_funct3(x) << ")\n";
        cout << "rd:     " << bitset<5>(get_rd(x)) << " (" << get_rd(x) << ")\n";

        if (get_funct3(x) == 0b000) cout << "Instruction: ADDI\n";
        if (get_funct3(x) == 0b100) cout << "Instruction: XORI\n";
        if (get_funct3(x) == 0b110) cout << "Instruction: ORI\n";
        if (get_funct3(x) == 0b111) cout << "Instruction: ANDI\n";
        if (get_funct3(x) == 0b010) cout << "Instruction: SLTI\n";
        if (get_funct3(x) == 0b011) cout << "Instruction: SLTIU\n";
    }
    if (get_opcode(x) == 0b1100111) {
        cout << "imm:    " << bitset<20>(get_imm(x)) << " (" << get_imm(x) << ")\n";
        cout << "rs1:    " << bitset<5>(get_rs1(x)) << " (" << get_rs1(x) << ")\n";
        cout << "funct3: " << bitset<3>(get_funct3(x)) << " (" << get_funct3(x) << ")\n";
        cout << "rd:     " << bitset<5>(get_rd(x)) << " (" << get_rd(x) << ")\n";

        if (get_funct3(x) == 0b000) cout << "Instruction: JALR\n";
    }
    if (get_opcode(x) == 0b0001111) {
        if (get_funct3(x) == 0b000) {
            cout << "fence_end: " << bitset<4>(get_fence_end(x)) << " (" << get_fence_end(x) << ")\n";
            cout << "pred: " << bitset<4>(get_pred(x)) << " (" << get_pred(x) << ")\n";
            cout << "succ: " << bitset<4>(get_succ(x)) << " (" << get_succ(x) << ")\n";
            cout << "funct3: " << bitset<3>(get_funct3(x)) << " (" << get_funct3(x) << ")\n";
            cout << "rd:     " << bitset<5>(get_rd(x)) << " (" << get_rd(x) << ")\n";
            cout << "Instruction: FENCE\n";
        }
        if (get_funct3(x) == 0b001) {
            cout << "imm: " << bitset<12>(get_imm(x)) << " (" << get_imm(x) << ")\n";
            cout << "funct3: " << bitset<3>(get_funct3(x)) << " (" << get_funct3(x) << ")\n";
            cout << "rd: " << bitset<5>(get_rd(x)) << " (" << get_rd(x) << ")\n";
            cout << "Instruction: FENCE.I\n";
        }
    }
    if (get_opcode(x) == 0b1110011) {
        cout << "funct7: " << bitset<5>(get_funct7(x)) << " (" << get_funct7(x) << ")\n";
        cout << "bits: " << bitset<2>(get_bits(x)) << " (" << get_bits(x) << ")\n";
        cout << "rs2: " << bitset<5>(get_rs2(x)) << " (" << get_rs2(x) << ")\n";
        cout << "rs1: " << bitset<5>(get_rs1(x)) << " (" << get_rs1(x) << ")\n";
        cout << "funct3 :" << bitset<3>(get_funct3(x)) << " (" << get_funct3(x) << ")\n";
        cout << "rd: " << bitset<5>(get_rd(x)) << " (" << get_rd(x) << ")\n";

        if (get_rs2(x) == 0b00000) cout << "Instruction: ECALL\n";
        if (get_rs2(x) == 0b00001) cout << "Instruction: EBREAK\n";
    }
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

// --------------------- B-Type --------------------- (FEITO)
void B_division(int x) {

    cout << "\n=== B-Type camadas ===\n";
    cout << "imm11:   " << bitset<1>(get_imm11(x)) << " (" << get_imm11(x) << ")\n";
    cout << "imm4_1:  " << bitset<4>(get_imm4_1(x)) << " (" << get_imm4_1(x) << ")\n";
    cout << "funct3:  " << bitset<3>(get_funct3(x)) << " (" << get_funct3(x) << ")\n";
    cout << "rs1:     " << bitset<5>(get_rs1(x)) << " (" << get_rs1(x) << ")\n";
    cout << "rs2:     " << bitset<5>(get_rs2(x)) << " (" << get_rs2(x) << ")\n";
    cout << "imm10_5: " << bitset<5>(get_imm10_5(x)) << " (" << get_imm10_5(x) << ")\n";
    cout << "imm12:   " << bitset<12>(get_imm12(x)) << " (" << get_imm12(x) << ")\n";

    if (get_funct3(x) == 0b000) cout << "Instruction: BEQ\n";
    if (get_funct3(x) == 0b001) cout << "Instruction: BNE\n";
    if (get_funct3(x) == 0b100) cout << "Instruction: BLT\n";
    if (get_funct3(x) == 0b101) cout << "Instruction: BGE\n";
    if (get_funct3(x) == 0b110) cout << "Instruction: BLTU\n";
    if (get_funct3(x) == 0b111) cout << "Instruction: BGEU\n";
}

// --------------------- U-Type --------------------- (FEITO)
void U_division(int x) {

    cout << "\n=== U-Type camadas ===\n";
    cout << "imm[31:12]: " << bitset<25>(get_imm(x)) << " (" << get_imm(x) << ")\n";
    cout << "rd:         " << bitset<5>(get_rd(x)) << " (" << get_rd(x) << ")\n";

    if (get_opcode(x) == 0b0110111)
        cout << "Instruction: LUI" << endl;
    if (get_opcode(x) == 0b0010111)
        cout << "Instruction: AUIPC" << endl;
}

// --------------------- J-Type --------------------- (FEITO)
void J_division(int x) {

    cout << "\n=== J-Type camadas ===\n";
    cout << "imm20: " << bitset<1>(get_imm20(x)) << " (" << get_imm20(x) << ")\n";
    cout << "imm10_1: " << bitset<10>(get_imm10_1(x)) << " (" << get_imm10_1(x) << ")\n";
    cout << "imm11: " << bitset<1>(get_imm11(x)) << " (" << get_imm11(x) << ")\n";
    cout << "imm19_12: " << bitset<8>(get_imm19_12(x)) << " (" << get_imm19_12(x) << ")\n";
    cout << "rd:  " << bitset<5>(get_rd(x)) << " (" << get_rd(x) << ")\n";
    cout << "Instruction: JAL\n";
}

class Instruction_Register {
public:
    void decoder(int x) {
        if (type_identifier(x) == 'R') {
            R_division(x);
        }
        else if (type_identifier(x) == 'I') {
            I_division(x);
        }
        else if (type_identifier(x) == 'B') {
            B_division(x);
        }
        else if (type_identifier(x) == 'U') {
            U_division(x);
        }
        else if (type_identifier(x) == 'J') {
            J_division(x);
        }
        else{
            cout << "ERROR";
        }

    }
};

int main() {

    int n1 = 0b00000000000100000000000001110011, n2 = 0b00000000000011100010011010110011;

    Instruction_Register ir;

    ir.decoder(n1);

    return 0;
}