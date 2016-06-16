package br.unicamp.ic.mc302.telefone;

import java.util.*;

public class Telefone {
	
    private Collection <TelefoneListener> telefoneListeners = new ArrayList<TelefoneListener>();

    // método de suporte para testar a solução
    public void tocaFone(String numero, String data, String hora) {
        disparaTelefoneTocou(numero, data, hora);
    }

    // método de suporte para testar a solução
    public void atendeFone(String numero, String data, String hora) {
        disparaTelefoneAtendido(numero, data, hora);
    }

    public void addTelefoneListener(TelefoneListener tl) {
        if(!telefoneListeners.contains(tl)) {
            telefoneListeners.add(tl);
        }
    }

    public void removeTelefoneListener(TelefoneListener tl) {

        telefoneListeners.remove(tl);
    }

    private void disparaTelefoneTocou(String numero, String data, String hora) {
         TelefoneEvent evento = new TelefoneEvent(this, numero, data, hora);                
        for (TelefoneListener t : telefoneListeners) {
                t.telefoneTocou(evento);
        }
    }
            

    // disparaTelefoneAtendido() é semelhante a disparaTelefoneTocou()
    private void disparaTelefoneAtendido(String numero, String data, String hora) {
        TelefoneEvent evento = new TelefoneEvent(this, numero, data, hora);
        for (TelefoneListener t : telefoneListeners) {
                t.telefoneAtendido(evento);
        }        
    }
    
}
