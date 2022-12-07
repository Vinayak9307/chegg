public class Loan {
    private double loanAmount;
    private double annualInterestRate;
    private int loanMonths;

    public Loan(double loan_amount, double annual_interest, int months) {
        this.loanAmount = loan_amount;
        this.annualInterestRate = annual_interest;
        this.loanMonths = months;
    }

    public double getLoanAmount() {
        return loanAmount;
    }

    public void setLoanAmount(double lam) {
        if(lam < 0){
            throw new IllegalArgumentException("Loan: setLoanAmount: the loan amount must be non negative");
        }
        this.loanAmount = lam;
    }

    public double getAnnualInterestRate() {
        return annualInterestRate;
    }

    public void setAnnualInterestRate(double air) {
        if(air < 0){
            throw new IllegalArgumentException("Loan: setAnnualInterestRate: the annual loan interest rate must be non negative");
        }
        this.annualInterestRate = air;
    }

    public int getLoanMonths() {
        return loanMonths;
    }

    public void setLoanMonths(int months) {
        if(months < 0){
            throw new IllegalArgumentException("Loan: setLoanAmount: the loan amount must be non negative");
        }
        this.loanMonths = months;
    }

    private double getMonthlyInterestRate(){
        return this.annualInterestRate / 1200.0;
    }

    private double getMonthlyPayment(){
        double monthlyPayment = 0;
        monthlyPayment = (getMonthlyInterestRate() * 1000) / (1 - Math.pow(1 + getMonthlyInterestRate() , -getLoanMonths()));
        int precision = 100;
        return Math.floor(monthlyPayment * precision + 0.5) / precision;
    }
    private double getLoanCost(){
        double interestPaid = getLoanMonths() * getMonthlyPayment() - getLoanAmount();
        int precision = 100;
        return Math.floor(interestPaid * precision + 0.5) / precision;
    }

    @Override
    public String toString() {
        return "---------------------------------" +  "\n" +
                "           Loan Report           " + "\n" +
                "---------------------------------" + "\n" +
                "          Loan Amount: $" + getLoanAmount() + "\n" +
                " Annual Interest Rate: " + getAnnualInterestRate() + "%" + "\n" +
                "Loan's term in months: " + getLoanMonths() + "\n" +
                "      Monthly Payment: $" + getMonthlyPayment() + "\n" +
                "  Total Interest Paid: $" + getLoanCost() + "\n" ;
    }

    public String amortise(){
        StringBuilder amortiseString = new StringBuilder("-------------------------------------------" + "\n" +
                "           Amortization Schedule           " + "\n" +
                "               Monthly Payment           " + "\n" +
                "                   "+ String.format("%.2f",getMonthlyPayment()) + "\n" +
                "-------------------------------------------" + "\n" +
                "Month    Interest   Principal       Loan" + "\n" +
                "         paid       paid         Balance" + "\n" +
                "-----    --------   ---------    -------" + "\n" +
                "                                 " + getLoanAmount() + "\n");
        double previousBalance = getLoanAmount();
        double monthlyInterest = getMonthlyInterestRate();
        double totalInterest = 0;
        for(int i = 1 ; i <= getLoanMonths() ; i++){
            double interestPaid = monthlyInterest * previousBalance;
            double principalPaid = getMonthlyPayment() - interestPaid;
            double loanBalance = getLoanAmount() - principalPaid;
            totalInterest += interestPaid;
            amortiseString.append(String.format("%5d",i)).append("   ").append(String.format("%8.2f",interestPaid)).append("   ").append(String.format("%9.2f",principalPaid)).append("    ").append(String.format("%7.2f",loanBalance)).append("\n");
            previousBalance -= principalPaid;
        }
        amortiseString.append("Totals    ").append(String.format("%8.2f",totalInterest)).append("   ").append(String.format("%9.2f",getLoanAmount()));
        return amortiseString.toString();
    }
}
