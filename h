def hamming74_encode(data_bits):
 # data_bits: string of 4 bits, e.g., "1010"
 d = [int(x) for x in data_bits]
 # positions 1-7: P1 P2 D1 P3 D2 D3 D4
 h = [0]*7
 h[2] = d[0] # D1
 h[4] = d[1] # D2
 h[5] = d[2] # D3
 h[6] = d[3] # D4
 # Parity bits
 h[0] = h[2] ^ h[4] ^ h[6] # P1 covers 1,3,5,7
 h[1] = h[2] ^ h[5] ^ h[6] # P2 covers 2,3,6,7
 h[3] = h[4] ^ h[5] ^ h[6] # P3 covers 4,5,6,7
 return h
inp = "1010"
code = hamming74_encode(inp)
output = ''.join(str(x) for x in code)
print("7-bit Hamming code for input 1010:", output)