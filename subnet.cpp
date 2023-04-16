 
#include <iostream>
#include <string.h>
#include <stack>
#include <vector>
#include <math.h>
#include <sstream>
#define DELIM "."
#include <ctype.h>
#include <math.h>

using namespace std;

bool valid_part(char* s)
{
    int n = strlen(s);
     
  
    if (n > 3)
        return false;
     
    
    for (int i = 0; i < n; i++)
        if ((s[i] >= '0' && s[i] <= '9') == false)
            return false;
    string str(s);
     
  
    if (str.find('0') == 0 && n > 1)
        return false;




    //reads string as if it was integer
    stringstream inp(str);
    int x;
    inp>> x;
     
    return (x >= 0 && x <= 255);
}
 


int is_valid_ip(char* ip_str)
{
    
    if (ip_str == NULL)
        return 0;
    int i, num, dots = 0;
    int len = strlen(ip_str);
    int count = 0;
     
    
    for (int i = 0; i < len; i++)
        if (ip_str[i] == '.')
            count++;
    if (count != 3)
        return false;
     
    char *ptr = strtok(ip_str, DELIM);
    if (ptr == NULL)
        return 0;
 
    while (ptr) {
 
       
        if (valid_part(ptr))
        {
           
            ptr = strtok(NULL, ".");
            if (ptr != NULL)
                ++dots;
        }
        else
            return 0;
    }
 
    if (dots != 3)
        return 0;
    return 1;
}


vector<int> bina(vector<string> str)
	{
	vector<int> re(32,0);
		int a, b, c, d, i, rem;
		a = b = c = d = 1;
		stack<int> st;

			a = stoi(str[0]);
			b = stoi(str[1]);
			c = stoi(str[2]);
			d = stoi(str[3]);

		// convert first number to binary
		for (i = 0; i <= 7; i++)
		{
			rem = a % 2;
			st.push(rem);
			a = a / 2;
		}

		// Obtain First octet
		for (i = 0; i <= 7; i++) {
			re[i] = st.top();
			st.pop();
		}

		for (i = 8; i <= 15; i++) {
			rem = b % 2;
			st.push(rem);
			b = b / 2;
		}

		for (i = 8; i <= 15; i++) {
			re[i] = st.top();
			st.pop();
		}

		for (i = 16; i <= 23; i++) {
			rem = c % 2;
			st.push(rem);
			c = c / 2;
		}

		for (i = 16; i <= 23; i++) {
			re[i] = st.top();
			st.pop();
		}
		
		for (i = 24; i <= 31; i++) {
			rem = d % 2;
			st.push(rem);
			d = d / 2;
		}

	for (i = 24; i <= 31; i++) {
			re[i] = st.top();
			st.pop();
		}

		return (re);
	}

char cls(vector<string> str)
	{	//we need just first 3 digits ...167 in this case
		int a = stoi(str[0]);
		if (a >= 0 && a <= 127)
			return ('A');
		else if (a >= 128 && a <= 191)
			return ('B');
		else if (a >= 192 && a <= 223)
			return ('C');
		else if (a >= 224 && a <= 239)
			return ('D');
		else
			return ('E');
	}


vector<int> deci(vector<int> bi)
	{  //[][][][]
    	vector<int> arr(4,0);
		int a, b, c, d, i, j;
		a = b = c = d = 0;
		j = 7;
		//10100111....2^7*1+  2^6*0 ...
		for (i = 0; i < 8; i++) {

			a = a + (int)(pow(2, j)) * bi[i];
			j--;
		}

		j = 7;
		for (i = 8; i < 16; i++) {

			b = b + bi[i] * (int)(pow(2, j));
			j--;
		}

		j = 7;
		for (i = 16; i < 24; i++) {

			c = c + bi[i] * (int)(pow(2, j));
			j--;
		}
        j = 7;
		for (i = 24; i < 32; i++) {

			d = d + bi[i] * (int)(pow(2, j));
			j--;
		}
        arr[0] = a;
		arr[1] = b;
		arr[2] = c;
		arr[3] = d;
		return arr;
	}
	
	
	void printSubnetInfo(u_int32_t* addressOctets, int* CIDR, int* subnetBits) {
	// Prints infomation about the given subnet.
	// Takes pointers to the required data, however does not change anything within them.
	// Any required manipulation is done with local variables

	u_int32_t netAddress;
	u_int32_t netMask;
	
	netMask = (0xFFFFFFFF << (32 - (*CIDR + *subnetBits)) & 0xFFFFFFFF);
	netAddress = *addressOctets & netMask;

	// Unpack and display the network address
	printf("\nNetwork address: %d.%d.%d.%d/%d\n", (netAddress >> 24) & 0xFF, (netAddress >> 16) & 0xFF,
						    (netAddress >> 8) & 0xFF, (netAddress) & 0xFF, *CIDR + *subnetBits);

	// Subtract the network address from the broadcast address and take one from the result for total hosts
	printf("Total hosts: %d\n", ((netAddress | ~netMask) - netAddress) - 1);

	// Display the first host address by adding to each of our unpacked octets
	printf("First host address: %d.%d.%d.%d\n", ((netAddress + 1) >> 24) & 0xFF, ((netAddress + 1) >> 16) & 0xFF,
						    ((netAddress + 1) >> 8) & 0xFF, (netAddress + 1) & 0xFF);
	
	// Bitwise OR the address int with the negated mask to get the broadcast address in the variable
	netAddress = netAddress | ~netMask;

	// Subtract from the from the broadcast address for the final host address
	printf("Last host address: %d.%d.%d.%d\n", ((netAddress - 1) >> 24) & 0xFF, ((netAddress - 1) >> 16) & 0xFF,
						   ((netAddress - 1) >> 8) & 0xFF, (netAddress - 1) & 0xFF);
	
	// Unpack and display the broadcast address
	printf("Broadcast address: %d.%d.%d.%d\n", (netAddress >> 24) & 0xFF, (netAddress >> 16) & 0xFF,
						   (netAddress >> 8) & 0xFF, (netAddress) & 0xFF);
}


int ipVerify(char* ipAddress, unsigned char* octetArray) {
	// Function verifies a valid IP has been entered, and then updates the octal array with the validated octets

	char* token;
	int i = 0;
	int j = 0;
	int periodCount = 0;

	// We will continue grabbing tokens whilst it isn't null
	token = strtok(ipAddress, ".");
	while (token != NULL) {

		// Loop through each character and check it's a digit
		// If it isn't break out. We use j to see if it looped the right amount of times
		for (j=0; j<strlen(token); j++) {
			if (isdigit(token[j]) == 0) {
				break;
			}
		}

		// If the right amount of digits have been entered, confirm octet as validated and add to array
		if (strlen(token) > 0 && strlen(token) < 4 && j == strlen(token)
				&& atoi(token) < 256 && atoi(token) >= 0) {
			periodCount++;
			octetArray[i] = atoi(token);
		} else {
			// No point in continuing if even one octet fails the test
			break;
		}

		i++;

		token = strtok(NULL, ".");
	}

	if (periodCount != 4) {
		return 0;
	} else {

		return 1;
	}
}

int main()
	{   cout<<"--------------------------------------------"<<endl;
        cout<<"------SUBNET CALCULATOR WITH IP VALIDATOR---"<<endl;
         cout<<"--------------------------------------------"<<endl;
         cout<<endl;cout<<endl;cout<<endl;

		string ipr = "192.168.100.0/26";
        		char ip1[]="192.168.100.0";
        	
        		char ipAddress[]="192.168.512.0";
        			ipAddress[strlen(ipAddress)-1] = '\0';
        		
		cout<<"IP address CIDR format is:"<< ipr;
		cout<<endl;
		
	    if(is_valid_ip(ip1) )	
		cout<<"Valid IP address\n" ;
		
		else if(is_valid_ip(ip1)==0)
		{   cout<<"Not valid IP address\n";
		    exit(-1);
		}
	
		// Separate IP address and n
		string str1 = "";
		int idx = 0;
		int len = ipr.size();
		len -= 3;
		//will run 14 times for above ip
		while(len--){
			str1 += ipr[idx];
			idx++;
		}
		cout<<endl;
		cout<<"IP Address : " <<str1<<endl;//stores ip without network mask

		string str2 = "";
		idx++;
		str2 += ipr[idx];
		idx++;
		str2 += ipr[idx];
		cout<<endl;
		cout<<"Value of n : "<< str2<<endl;//stores network mask;
		// IP address
		string tr = str1;

		// Split IP address into 4 subparts x, y, z, t
	
		vector<string> str;

		string temp;
		int n = tr.size();
		for(int i = 0; i < n; i++){

				//0...9, then append string to temp
			if(tr[i] >= 48 && tr[i] <= 57)
				temp +=tr[i];
			else{		//if . encountred , push entire string till dot in vector and clear temp
				str.push_back(temp);
				temp = "";
			}
		}
		str.push_back(temp);//str now contains "167""199""170""82"
	

		vector<int> b;

		cout<<endl;
		b = bina(str);
		
		cout<<"IP address in binary:"<<endl;

			//printing ip ad in binary
		for(int i=0;i<8;i++){
		    	cout<<b[i];
		}
	    cout<<"  ";
	    	for(int i=8;i<16;i++){
		    	cout<<b[i];
		}
		cout<<"  ";
			for(int i=16;i<24;i++){
		    	cout<<b[i];
		}cout<<"  ";
			for(int i=24;i<32;i++){
		    	cout<<b[i];
		}cout<<"  ";
	    cout<<endl;
		

		n = stoi(str2);
		vector<int> ntwk(32,0);
		vector<int> brd(32,0);
		int t = 32 - n;

		for (int i = 0; i <= (31 - t); i++) {

			ntwk[i] = b[i];
			brd[i] = b[i];
		}

		// Set 32-n bits to 0
		for (int i = 31; i > (31 - t); i--) {

			ntwk[i] = 0;
		}
		cout<<endl;
		cout<<"First address in binary:"<<endl;
		for(int i=0;i<8;i++){
		    	cout<<ntwk[i];
		}
	    cout<<"  ";
	    	for(int i=8;i<16;i++){
		    	cout<<ntwk[i];
		}cout<<"  ";
			for(int i=16;i<24;i++){
		    	cout<<ntwk[i];
		}cout<<"  ";
			for(int i=24;i<32;i++){
		    	cout<<ntwk[i];
		}cout<<"  ";
	    cout<<endl;


		// setting 32-n bits of broadcast address to 1
		for (int i = 31; i > (31 - t); i--) {

			brd[i] = 1;
		}

		cout<<endl;
		
			cout<<"Last address in binary:"<<endl;
		for(int i=0;i<8;i++){
		    	cout<<brd[i];
		}
	    cout<<"  ";
	    	for(int i=8;i<16;i++){
		    	cout<<brd[i];
		}cout<<"  ";
			for(int i=16;i<24;i++){
		    	cout<<brd[i];
		}cout<<"  ";
			for(int i=24;i<32;i++){
		    	cout<<brd[i];
		}cout<<"  ";
	    cout<<endl;
	    cout<<endl;

		char c = cls(str);
		cout<<"Class : " << c << endl;

		vector<int> nt = deci(ntwk);

		vector<int> br = deci(brd);
		cout<<endl;

		cout<<"First Address : " << nt[0] << "." <<nt[1] <<"." << nt[2] <<"." << nt[3]<<endl;
		cout<<endl;
		cout<<"Last Address : " <<br[0] << "." <<br[1] << "." << br[2] <<"." << br[3] << endl;
		cout<<endl;
		
		cout<<"IP Range:"<< nt[0] << "." <<nt[1] <<"." << nt[2] <<"." << nt[3]+1<<
		" to "<<br[0] << "." <<br[1] << "." << br[2] <<"." << br[3] -1<< endl;
        cout<<endl;
		
		int N=stoi(str2);
		long long int address=pow(2,32-N);
		
		cout<<"Total Number of Addresses :"<<address <<endl;
		cout<<endl;
		cout<<"Total Number of usable hosts per network :"<<address-2<<endl;
		
			
		
		
		int subnetNumber;
    	int subnetBits = 0;
    	int totalSubnets = 0;
	    u_int32_t currentSubnet;
	    u_int32_t addressOctets;
	    unsigned char* octetArray;
	    octetArray = new unsigned char[4];
	    int x=ipVerify(ipAddress, octetArray);
		
		char buffer[256];
		
		
			
	    addressOctets = (octetArray[0] << 24) | (octetArray[1] << 16) | (octetArray[2] << 8) | (octetArray[3]);
	  
			do {
		printf("Enter number of required networks, or q to quit: ");
		fgets(buffer, 4, stdin);
		subnetNumber = atoi(buffer);

		if (subnetNumber == 0) {
			printf("Exiting...\n");
			exit(0);
		}

		// Determine the amount of bits required to contain the required networks
		while (subnetNumber > totalSubnets) {
			subnetBits++;
			totalSubnets = pow(2, subnetBits);
		}

		// Check we have the required amount of bits to subnet successfully
		if ((n + subnetBits) > 31) {
			printf("Amount of networks too large to be accommodated.\n");
		}
	} while ((n + subnetBits) > 31);

	printf("\nTotal subnets to be created: %d\n-------------------------------", totalSubnets); 
			for (int i=0; i<totalSubnets; i++) {
		currentSubnet = (addressOctets & ((0xFFFFFFFF << (32 - n)) & 0xFFFFFFFF))
				| i << (32 - (n + subnetBits));
		printSubnetInfo(&currentSubnet, &n, &subnetBits);
	}

	
		

        
		return 0;
        }
