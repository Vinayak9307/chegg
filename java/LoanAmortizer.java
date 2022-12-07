import java.util.Scanner;

public class LoanAmortizer {
    public static void main(String[] args) {
        Scanner my_keyboard = new Scanner(System.in);
        char answer;
        do{
            // Get the loan amount
            System.out.print("Enter the loan amount: ");
            double loan = my_keyboard.nextDouble();

            System.out.print("Enter the interest rate: ");
            double interestRate = my_keyboard.nextDouble();

            System.out.print("Enter loan's term in months: ");
            int months = my_keyboard.nextInt();

            Loan a_loan = new Loan(loan , interestRate , months);

            System.out.println(a_loan);
            System.out.println(a_loan.amortise());

            System.out.print("Would you like to run another report?\n"+
                             "Enter Y or y for yes , or any other character for no: ");
            answer = my_keyboard.next().charAt(0);
            answer = Character.toLowerCase(answer);
        }while (answer == 'y');
        System.out.println("GoodBye!");
    }
}
