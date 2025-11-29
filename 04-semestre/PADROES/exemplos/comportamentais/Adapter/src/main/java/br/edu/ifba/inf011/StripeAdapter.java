package br.edu.ifba.inf011;

public class StripeAdapter implements PaymentGateway{

  private Stripe stripe;

  public StripeAdapter(Stripe stripe) {
    this.stripe = stripe;
  }

  @Override
  public void processPayment(String amount) {
    stripe.makePayment(amount);
  }
}
