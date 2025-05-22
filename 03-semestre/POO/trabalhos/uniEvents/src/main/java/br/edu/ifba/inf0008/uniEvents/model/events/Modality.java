package br.edu.ifba.inf0008.uniEvents.model.events;

public enum Modality {
  INPERSON("In Person"){
    @Override
    public String getInstructions() {
      return "Instructions for the in-person event: Check the address, the event time, and present the proof.";
    }
  },
  ONLINE("Online"){
    @Override
    public String getInstructions() {
      return "Instructions for the online event: Check the access link, the event time, and enter the access code.";
    }
  },
  HYBRID("Hybrid (In-Person and Online)"){
    @Override
    public String getInstructions() {
      return "Instructions for the hybrid event: Check the physical or virtual address, the event time, and present the proof or access code.";
    }
  };

  private final String description;

  Modality(String description) {
    this.description = description;
  }

  public abstract String getInstructions();
  //public abstract void processRegistration();
  @Override
  public String toString() {
    return description;
  }
}
