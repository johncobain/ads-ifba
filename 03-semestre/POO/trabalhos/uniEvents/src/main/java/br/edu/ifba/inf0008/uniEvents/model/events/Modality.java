package br.edu.ifba.inf0008.uniEvents.model.events;

public enum Modality {
  PRESENCIAL("Presencial"){
    @Override
    public String getInstructions() {
      return "Instruções para o evento presencial: Verifique o endereço, o horário do evento e apresente o comprovante.";
    }
  },
  ONLINE("Online"){
    @Override
    public String getInstructions() {
      return "Instruções para o evento online: Verifique o link de acesso, o horário do evento e insira o código de acesso.";
    }
  },
  HIBRIDO("Híbrido (Online e Presencial)"){
    @Override
    public String getInstructions() {
      return "Instruções para o evento híbrido: Verifique o endereço físico ou virtual, o horário do evento e apresente o comprovante ou o código de acesso.";
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
