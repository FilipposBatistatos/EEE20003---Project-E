/*
    To design LED matrix with few features. 
    Make a proper connection for 8×8 LED Matrix with resistors 
    to the microcontroller. The LED matrix have to be constructed 
    manually by using 64 units of LED as 8×8 LED Matrix. Display 
    your name andscroll from right to left continuously.
*/

bool ALL[8][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}};
bool EMP[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
bool EX[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
bool A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 0, 0}, {0, 1, 1, 0, 0, 1, 1, 0}, {0, 1, 1, 0, 0, 1, 1, 0}, {0, 1, 1, 1, 1, 1, 1, 0}, {0, 1, 1, 0, 0, 1, 1, 0}, {0, 1, 1, 0, 0, 1, 1, 0}, {0, 1, 1, 0, 0, 1, 1, 0}};
bool B[8][8] = {{0, 1, 1, 1, 1, 0, 0, 0}, {0, 1, 0, 0, 1, 0, 0, 0}, {0, 1, 0, 0, 1, 0, 0, 0}, {0, 1, 1, 1, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 0, 0, 0}, {0, 1, 0, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 1, 0, 0}, {0, 1, 1, 1, 1, 1, 0, 0}};
bool C[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 1, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 1, 1, 0}};
bool D[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
bool E[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
bool F[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
bool G[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 1, 1, 1, 0}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 0, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
bool H[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 0, 1, 1, 1, 1, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
bool I[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
bool J[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 1, 0, 1, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
bool K[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 1, 0, 0, 0}, {0, 0, 1, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
bool L[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
bool M[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 1, 0, 0}, {1, 0, 1, 0, 1, 0, 1, 0}, {1, 0, 0, 1, 0, 0, 1, 0}, {1, 0, 0, 0, 0, 0, 1, 0}, {1, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
bool N[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 0, 1, 1, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 0, 1, 0}, {0, 0, 1, 0, 0, 1, 1, 0}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
bool O[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 0, 0}, {0, 1, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
bool P[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
bool Q[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 0, 0}, {0, 1, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 1, 1, 0}, {0, 0, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 1}};
bool R[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
bool S[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
bool T[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
bool U[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
bool V[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 0, 0, 1, 0, 1, 0, 0}, {0, 0, 0, 1, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
bool W[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 1, 0}, {1, 0, 0, 1, 0, 0, 1, 0}, {0, 1, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 1, 0, 1, 0, 0}, {0, 0, 1, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
bool X[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
bool Y[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
bool Z[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};

bool FRAME[8][8];

bool MSG[8][500];
int displayLength;
int offset = 0;

int frameSpeed = 500;
int previousTime;

const int rows[8] = {22, 24, 26, 28, 30, 32, 34, 36};
const int cols[8] = {23, 25, 27, 29, 31, 33, 35, 37};
//const int cols[8] = {37, 35, 33, 31, 29, 27, 25, 23};

void prepareMessage(String msg)
{
    int msg_len = msg.length() + 1;
    char char_array[msg_len];

    displayLength = (msg_len + 2) * 8;

    msg.toCharArray(char_array, msg_len);

    addFrame(EMP, 0);

    for (int i = 0; i < msg_len + 1; i++)
    {
        char character = char_array[i];
        if (character == 'A' or character == 'a')
        {
            addFrame(A, (i + 1) * 8);
        }
        else if (character == 'B' or character == 'b')
        {
            addFrame(B, (i + 1) * 8);
        }
        else if (character == 'C' or character == 'c')
        {
            addFrame(C, (i + 1) * 8);
        }
        else if (character == 'D' or character == 'd')
        {
            addFrame(D, (i + 1) * 8);
        }
        else if (character == 'E' or character == 'e')
        {
            addFrame(E, (i + 1) * 8);
        }
        else if (character == 'F' or character == 'f')
        {
            addFrame(F, (i + 1) * 8);
        }
        else if (character == 'G' or character == 'g')
        {
            addFrame(G, (i + 1) * 8);
        }
        else if (character == 'H' or character == 'h')
        {
            addFrame(H, (i + 1) * 8);
        }
        else if (character == 'I' or character == 'i')
        {
            addFrame(I, (i + 1) * 8);
        }
        else if (character == 'J' or character == 'j')
        {
            addFrame(J, (i + 1) * 8);
        }
        else if (character == 'K' or character == 'k')
        {
            addFrame(K, (i + 1) * 8);
        }
        else if (character == 'L' or character == 'l')
        {
            addFrame(L, (i + 1) * 8);
        }
        else if (character == 'M' or character == 'm')
        {
            addFrame(M, (i + 1) * 8);
        }
        else if (character == 'N' or character == 'n')
        {
            addFrame(N, (i + 1) * 8);
        }
        else if (character == 'O' or character == 'o')
        {
            addFrame(O, (i + 1) * 8);
        }
        else if (character == 'P' or character == 'p')
        {
            addFrame(P, (i + 1) * 8);
        }
        else if (character == 'Q' or character == 'q')
        {
            addFrame(Q, (i + 1) * 8);
        }
        else if (character == 'R' or character == 'r')
        {
            addFrame(R, (i + 1) * 8);
        }
        else if (character == 'S' or character == 's')
        {
            addFrame(S, (i + 1) * 8);
        }
        else if (character == 'T' or character == 't')
        {
            addFrame(T, (i + 1) * 8);
        }
        else if (character == 'U' or character == 'u')
        {
            addFrame(U, (i + 1) * 8);
        }
        else if (character == 'V' or character == 'v')
        {
            addFrame(V, (i + 1) * 8);
        }
        else if (character == 'W' or character == 'w')
        {
            addFrame(W, (i + 1) * 8);
        }
        else if (character == 'X' or character == 'x')
        {
            addFrame(X, (i + 1) * 8);
        }
        else if (character == 'Y' or character == 'y')
        {
            addFrame(Y, (i + 1) * 8);
        }
        else if (character == 'Z' or character == 'z')
        {
            addFrame(Z, (i + 1) * 8);
        }
        else
        {
            addFrame(EMP, (i + 1) * 8);
        } //End of character check if statement
    }

    updateFrame();
}

void addFrame(bool character[8][8], int padding)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            MSG[i][j + padding] = character[i][j];
        }
    }
}

void updateFrame()
{
    offset++;
    if (offset + 16 > displayLength)
        offset = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            FRAME[i][j] = MSG[i][j + offset];
        }
    }
}

//=================== Draw a 8x8 matrix ====================
void drawScreen(bool buffer2[8][8])
{
    // Turn on each row in series
    for (byte i = 0; i < 8; i++)
    {                               // count next row
        digitalWrite(rows[i], LOW); //initiate whole row
        for (byte a = 0; a < 8; a++)
        { // count next row
            // if You set (~buffer2[i] >> a) then You will have positive
            digitalWrite(cols[a], buffer2[i][a]); // initiate whole column

            delayMicroseconds(100); // uncoment delay for diferent speed of display

            digitalWrite(cols[a], 0); // reset whole column
        }
        digitalWrite(rows[i], HIGH); // reset whole row
                                     // otherwise last row will intersect with next row
    }
}
//===================== End of draw ========================

void setup()
{
    Serial.begin(9600);
    for (int i = 0; i < 8; i++)
    {
        pinMode(rows[i], OUTPUT);
        digitalWrite(rows[i], HIGH);
        pinMode(cols[i], OUTPUT);
        digitalWrite(cols[i], LOW);
    }

    String message = "Philip";
    prepareMessage(message);
    previousTime = millis();
}

void loop()
{
    drawScreen(FRAME);
    if (millis() > previousTime + frameSpeed)
    {
        Serial.println("Updating frame");
        updateFrame();
        previousTime = millis();
    }
}