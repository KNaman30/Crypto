clear;
plaintext = input('Enter the plaintext :','s');
%convert the plain text to bits(64 bits)5
binaryplaintext = dec2bin(plaintext,8);
binaryplaintext = reshape(binaryplaintext.'-'0',1,[]);
binaryplaintext = padarray(binaryplaintext,[0,mod(-numel(binaryplaintext),64)],0,'post');
binaryplaintext = reshape(binaryplaintext,64,[]).';

key = input('Enter the key :','s');
%convert the key to bits(32 bits)
key = dec2bin(key,8);
key = reshape(key.'-'0',1,[]);
if length(key) < 32
    key = padarray(key,[0,mod(-numel(key),32)],0,'post');
else
    key = key(1:32);
end

%%%%%%  Encrypting  %%%%%%
ciphertext = zeros(size(binaryplaintext));
for i=1:size(binaryplaintext,1)
    leftpart = binaryplaintext(i,1:32);
    rightpart = binaryplaintext(i,33:end);
    temp = rightpart;
    rightpart = bitxor(key,rightpart);
    rightpart = bitxor(rightpart,leftpart);
    leftpart = temp;

    for x=1:64
        if x<33
            ciphertext(i,x) = rightpart(x);
        else
            ciphertext(i,x) = leftpart(x-32);
        end
    end
end
%%%%% DISPLAY IN HEXA %%%%%
ciphertext = reshape(char(ciphertext.'+'0'),4,[]).';
ciphertext = bin2dec(ciphertext).';
ciphertext = dec2hex(ciphertext).';
fprintf("Ciphertext --> ");
disp(ciphertext);

%%%%% convert HEX to bin %%%%%
BRPL = hex2dec(ciphertext.');
BRPL = dec2bin(BRPL,4);
BRPL = reshape(BRPL'-'0',64,[]).';

%%%%% decrypting  %%%%%
RPL = zeros(size(BRPL));
for i=1:size(BRPL,1)
    leftpart = BRPL(i,1:32);
    rightpart = BRPL(i,33:end);
    temp = rightpart;
    rightpart = bitxor(rightpart,leftpart);
    rightpart = bitxor(key,rightpart);
    leftpart = temp;
    for x=1:64
        if x<33
            RPL(i,x) = rightpart(x);
        else
            RPL(i,x) = leftpart(x-32);
        end
    end
end

%%%%% SHOwing TEXT %%%%%
RPL = reshape(char(RPL.'+'0'),8,[]).';
RPL = bin2dec(RPL).';
RPL = char(RPL);
fprintf("Recovered Plaintext --> ");
disp(RPL);
