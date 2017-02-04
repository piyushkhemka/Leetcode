class Solution {
public:
    string numberToWords(int num) {

        int n = 0;
        int temp = num;

        while(temp) {
            n++;
            temp = temp/10;
        }

        if(num == 0)
            return "Zero";

        string result = "";

        unordered_map<int, string> dtol = { {1,"One"}, {2,"Two"}, {3,"Three"}, {4,"Four"}, {5,"Five"}, {6,"Six"},
                                            {7,"Seven"}, {8,"Eight"}, {9,"Nine"}, {10,"Ten"}, {0,"Zero"}};

        unordered_map<int, string> tens = {{1,"One"}, {2,"Twenty"}, {3,"Thirty"}, {4,"Forty"}, {5,"Fifty"},
                                            {6,"Sixty"}, {7,"Seventy"},{8,"Eighty"}, {9,"Ninety"},{10, "Ten"},
                                            {11,"Eleven"}, {12,"Twelve"},{13,"Thirteen"}, {14,"Fourteen"},{15, "Fifteen"},
                                            {16,"Sixteen"}, {17,"Seventeen"},{18,"Eighteen"}, {19,"Nineteen"}};

        while(n) {

            if (n == 1) {

                if(num == 0 && !result.empty()) {
                    n--;
                    break;
                }

                if(!result.empty())
                    result += " ";

                result += dtol[num];
                n--;
            }

            else if (n==2) {

                if(num/10 == 0) {
                    n--;
                    continue;
                }

                if(num/10 == 1) {

                    if(!result.empty())
                        result += " ";

                    result += tens[num];
                    n = n-2;
                }
                else {

                    if(!result.empty())
                        result += " ";

                    result += tens[num/10];
                    num = num%10;
                    n--;
                }
            }

            else if (n==3) {

                if(num/100 == 0) {
                    n--;
                    continue;
                }

                if(!result.empty())
                    result += " ";
                result += dtol[num/100] + " Hundred"; // One Hundred
                n--;
                num = num % 100;

            }

            else if (n==4) {

                if(num/1000 == 0) {
                    n--;
                    continue;
                }
                if(!result.empty())
                    result += " ";
                result += dtol[num/1000] + " Thousand"; // One Thousand
                n--;
                num = num % 1000;

            }

            else if (n==5) {

                if(num/10000 == 0) {
                    n--;
                    continue;
                }
                if(!result.empty())
                    result += " ";
                result += numberToWords(num/1000) + " Thousand";
                n = n-2;
                num = num % 1000;

            }

            else if (n==6) {

                if(num/100000 == 0) {
                    n--;
                    continue;
                }
                if(!result.empty())
                    result += " ";
                result += numberToWords(num/1000)+ " Thousand";
                n = n-3;
                num = num % 1000;

            }

            else if (n==7) {

                if(num/1000000 == 0) {
                    n--;
                    continue;
                }
                if(!result.empty())
                    result += " ";
                result += dtol[num/1000000] + " Million";
                n = n--;
                num = num % 1000000;

            }

            else if (n==8) {

                if(num/10000000 == 0) {
                    n--;
                    continue;
                }
                if(!result.empty())
                    result += " ";
                result += numberToWords(num/1000000)+ " Million";
                n = n-2;
                num = num % 1000000;
            }

            else if (n==9) {

                if(num/100000000 == 0) {
                    n--;
                    continue;
                }
                if(!result.empty())
                    result += " ";
                result += numberToWords(num/1000000)+ " Million";
                n = n-3;
                num = num % 1000000;

            }


            else if (n==10) {

                if(num/1000000000 == 0) {
                    n--;
                    continue;
                }
                if(!result.empty())
                    result += " ";
                result += dtol[num/1000000000] + " Billion";
                n = n--;
                num = num % 1000000000;

            }

        }

        return result;

    }
};
