package br.edu.ifba.inf008.reading;

import java.util.Set;


public class Member{
  private String name;
  private String adress;
  private String birthDate;
  private Set<Book> books;

  public Member(String adress, String birthDate, String name) {
    this.adress = adress;
    this.birthDate = birthDate;
    this.name = name;
  }

  public String getName() {
    return name;
  }
  public void setName(String name) {
    this.name = name;
  }
  public String getAdress() {
    return adress;
  }
  public void setAdress(String adress) {
    this.adress = adress;
  }
  public String getBirthDate() {
    return birthDate;
  }
  public void setBirthDate(String birthDate) {
    this.birthDate = birthDate;
  }
  public Set<Book> getBooks() {
    return books;
  }
  public void setBooks(Set<Book> books) {
    this.books = books;
  }
}