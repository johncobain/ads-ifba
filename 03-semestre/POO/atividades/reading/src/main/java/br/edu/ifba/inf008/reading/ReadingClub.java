package br.edu.ifba.inf008.reading;

import java.util.Set;

public class ReadingClub {
  private Set<Book> books;
  private Set<Member> members;
  private Set<Meeting> meetings;

  public int numberOfMembers(){
    return 0;
  }

  public Book mostRecommendedBook(){
    return new Book("null", 0);
  }

  public Set<Book> getBooks() {
    return books;
  }

  public void setBooks(Set<Book> books) {
    this.books = books;
  }

  public Set<Member> getMembers() {
    return members;
  }

  public void setMembers(Set<Member> members) {
    this.members = members;
  }

  public Set<Meeting> getMeetings() {
    return meetings;
  }

  public void setMeetings(Set<Meeting> meetings) {
    this.meetings = meetings;
  }

  
}
