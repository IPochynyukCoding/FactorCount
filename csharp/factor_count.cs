List<ulong> factor_calculate(ulong number){
    List<ulong> factor_values= new List<ulong>{};
    for (ulong i =1;i<Math.Round(Math.Sqrt(number));i++){
        if (number % i == 0){
            factor_values.Add(i);
            factor_values.Add(number/i);
        }
    }
    if (Math.Floor(Math.Sqrt(number)) == Math.Sqrt(number)){
        factor_values.Add((ulong)Math.Floor(Math.Sqrt(number)));
    }
    factor_values.Sort();
    return factor_values;
}
void main(){
    int EXIT_SUCCESS=0;
    while (true){
            bool is_valid_input=false;
            ulong real_number=0;
            string? number_input;
            while (!is_valid_input){
                Console.Write("Insert a number to check its factors or press 'q' to quit: ");
                number_input=Console.ReadLine();
                try{
                    if(number_input.Equals("q", StringComparison.CurrentCultureIgnoreCase)){
                            Environment.Exit(EXIT_SUCCESS);
                    }
                    real_number= Convert.ToUInt64(number_input);
                }
                catch(FormatException){
                    Console.WriteLine("This input is invalid because it is not a valid number!");
                    continue;
                }
                catch (OverflowException){
                    Console.WriteLine("This input is not valid because the number is outside the bounds of this program");
                    continue;
                }
                is_valid_input=true;
            }
            List<ulong> factors=factor_calculate(real_number);
            Console.WriteLine($"Factors of {real_number}: [{string.Join(",",factors)}]");

            if (real_number<2){
                Console.WriteLine($"{real_number} is not prime because it is smaller than 2.");
                }
            Console.WriteLine($"{real_number} is {(factors.Count!=2?"not ":"")}prime because it has {factors.Count} factors.");
        }
}

main();