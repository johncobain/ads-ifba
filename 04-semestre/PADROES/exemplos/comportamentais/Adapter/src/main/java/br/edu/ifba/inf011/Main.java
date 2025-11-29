package br.edu.ifba.inf011;

public class Main {
  public static void main(String[] args) {
    Paypal paypal = new Paypal();
    PaymentGateway paymentGateway = new PaypalAdapter(paypal);
    paymentGateway.processPayment("100");

    Stripe stripe = new Stripe();
    PaymentGateway stripePaymentGateway = new StripeAdapter(stripe);
    stripePaymentGateway.processPayment("100");
  }
}
