package br.edu.ifba.inf008.reading;

public class Book{
  private String name;
  private int pages;
  private double rate;
  private int rateCount;
  
  private static int bookCount = 0;

  public Book(String name, int pages) {
    this.name = name;
    this.pages = pages;
    this.rate = 0;
    ++bookCount;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public int getPages() {
    return pages;
  }

  public void setPages(int pages) {
    this.pages = pages;
  }

  public double getRate() {
    return rate;
  }

  public void setRate(double rate) {
    this.rateCount++;
    this.rate = (this.rate+rate)/this.rateCount;
  }

  public static int getBookCount() {
    return bookCount;
  }

}