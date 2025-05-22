package br.edu.ifba.inf0008.uniEvents.model.events;

import java.time.LocalDate;
import java.util.ArrayList;

import br.edu.ifba.inf0008.uniEvents.model.participants.Participant;

public abstract class Event {
  private String name;
  private String description;
  private String location;
  private LocalDate date;
  private int capacity;
  private Modality modality;
  private ArrayList<Participant> participants;
  
  public Event(String name, String description, String location, LocalDate date, int capacity, Modality modality) {
    this.name = name;
    this.description = description;
    this.location = location;
    this.date = date;
    this.capacity = capacity;
    this.modality = modality;
    this.participants = new ArrayList<>();
  }
}
