//Michael Dinh - CISP 401 - Hospital

//Hospital: has patient, doctor, drug, person
//Patient: is person, uses a drug, has a doctor
//Doctor: is person, has patients
//Drug: used by patients
//Person: can be a patient or a doctor
//One patient has one doctor; for simplicity's sake, each doctor only has one patient

final class Drug{
    String name;
    int dose;
    Drug(String name, int dose){
        this.name = name;
        this.dose = dose;
    }
    String getDrug(){
        return this.name;
    }
    int getDrugDose(){
        return this.dose;
    }
}

class Person{
    String name;
    Person(String name){
        this.name = name;
    }
    String getName(){
        return this.name;
    }
    void sayHi(){
        System.out.printf("%s says hi!", this.getName());
    }
}

class Patient extends Person{
    String diagnosis;
    Drug prescription;
    int noOfDrug;
    Doctor doctor;
    Patient(String name, String diagnosis){
        super(name);
        this.diagnosis = diagnosis;
        prescription = null;
        noOfDrug = 0;
    }
    String getDiagnosis(){
        return this.diagnosis;
    }
    Drug getPrescription(){
        return this.prescription;
    }
    int getNoOfDrugLeft(){
        return this.noOfDrug;
    }
    Doctor getDoctor(){
        return this.doctor;
    }
    void assignDoctor(Doctor doctor){
        this.doctor = doctor;
    }
    void assignPrescription(Drug prescription, int noOfDrug){
        this.prescription = prescription;
        this.noOfDrug = noOfDrug;
    }
    void takePrescription(){
        if(prescription == null){
            System.out.println("No prescription!");
            return;
        }
        else{
            noOfDrug -= prescription.getDrugDose();
            System.out.printf("%s took their prescription. %d pills left.\n", name, noOfDrug);
        }
        return;
    }
}

class Doctor extends Person{
    String profession;
    Patient patient;
    int noOfPatients = 0;
    Doctor(String name, String profession){
        super(name);
        this.profession = profession;
    }
    String getProfession(){
        return this.profession;
    }
    int getNoOfPatients(){
        return noOfPatients;
    }
    void assignPatient(Patient patient){
        this.patient = patient;
    }
    Patient getPatient(){
        return patient;
    }
}

class Hospital{
    String name, address;
    Hospital(String name, String address){
        this.name = name;
        this.address = address;
    }
    int noOfDrugs = 0;
    int noOfPatients = 0;
    int noOfDoctors = 0;
    Patient[] patients = new Patient[0];
    Doctor[] doctors = new Doctor[0];
    Drug[] drugs = new Drug[0];
    void addDrug(Drug drug){
        Drug[] temp = new Drug[drugs.length + 1];
        System.arraycopy(drugs, 0, temp, 0, drugs.length);
        temp[noOfDrugs] = drug;
        noOfDrugs += 1;
        drugs = temp;
    }
    void addPatient(Patient patient){
        Patient[] temp = new Patient[patients.length + 1];
        System.arraycopy(patients, 0, temp, 0, patients.length);
        temp[noOfPatients] = patient;
        noOfPatients += 1;
        patients = temp;
    }
    void addDoctor(Doctor doctor){
        Doctor[] temp = new Doctor[doctors.length + 1];
        System.arraycopy(doctors, 0, temp, 0, doctors.length);
        temp[noOfDoctors] = doctor;
        noOfDoctors += 1;
        doctors = temp;
    }
    Drug getDrug(int index){
        return drugs[index];
    }
    Patient getPatient(int index){
        return patients[index];
    }
    Doctor getDoctor(int index){
        return doctors[index];
    }
    int getNoOfDrugs(){
        return noOfDrugs;
    }
    int getNoOfPatients(){
        return noOfPatients;
    }
    int getNoOfDoctors(){
        return noOfDoctors;
    }
    String getName(){
        return name;
    }
    String getAddress(){
        return address;
    }
}

class Driver{
    public static void main(String[] args){
        //make hospital
        Hospital MercyHospital = new Hospital("Mercy Hospital", "1234 Medical Drive");
        //fill patients
        MercyHospital.addPatient(new Patient("Terry Bogard", "Broken ribcage"));
        MercyHospital.addPatient(new Patient("Vincent Pizzapasta", "Seizures"));
        MercyHospital.addPatient(new Patient("An actual monkey", "Lack of bananas"));
        //fill doctors
        MercyHospital.addDoctor(new Doctor("Derek Styles", "Surgeon"));
        MercyHospital.addDoctor(new Doctor("Maria Torres", "Paramedic"));
        MercyHospital.addDoctor(new Doctor("Valerie Blaylock", "Diagnostician"));
        //fill drugs
        MercyHospital.addDrug(new Drug("Diazepam", 1)); //seizures
        MercyHospital.addDrug(new Drug("Oxycodone", 1)); //pain relief
        MercyHospital.addDrug(new Drug("Bananas", 5)); //monkey time :)
        //display hospital instance variables
        System.out.printf("%s is located at %s.\n", MercyHospital.getName(), MercyHospital.getAddress());
        //display all patients, doctors, and drugs at the hospital
        for(int i = 0; i < MercyHospital.getNoOfDoctors(); i++){
            System.out.printf("Doctor #%d is %s, who is a(n) %s.\n", i+1, MercyHospital.getDoctor(i).getName(), MercyHospital.getDoctor(i).getProfession());
        }
        for(int i = 0; i < MercyHospital.getNoOfPatients(); i++){
            System.out.printf("Patient #%d is %s, who has been diagnosed with %s.\n", i+1, MercyHospital.getPatient(i).getName(), MercyHospital.getPatient(i).getDiagnosis());
        }
        for(int i = 0; i < MercyHospital.getNoOfDrugs(); i++){
            System.out.printf("Drug #%d is %s, which has a recommended dosage of %s pill(s).\n", i+1, MercyHospital.getDrug(i).getDrug(), MercyHospital.getDrug(i).getDrugDose());
        }
        //assign patients to doctors and et cetera
        MercyHospital.getPatient(0).assignDoctor(MercyHospital.getDoctor(0));
        MercyHospital.getPatient(1).assignDoctor(MercyHospital.getDoctor(1));
        MercyHospital.getPatient(2).assignDoctor(MercyHospital.getDoctor(2));
        MercyHospital.getDoctor(0).assignPatient(MercyHospital.getPatient(0));
        MercyHospital.getDoctor(1).assignPatient(MercyHospital.getPatient(1));
        MercyHospital.getDoctor(2).assignPatient(MercyHospital.getPatient(2));
        //assign prescriptions
        MercyHospital.getPatient(0).assignPrescription(MercyHospital.getDrug(1), 10);
        MercyHospital.getPatient(1).assignPrescription(MercyHospital.getDrug(0), 50);
        MercyHospital.getPatient(2).assignPrescription(MercyHospital.getDrug(2), 30);
        //pull a random doctor and display all patients
        System.out.printf("%s's patient is %s.\n", MercyHospital.getDoctor(1).getName(), MercyHospital.getDoctor(1).getPatient().getName());
        //pull a random patient, display all instance values, and test function
        System.out.printf("%s's doctor is %s, and has %s as their prescription for %s.\n", MercyHospital.getPatient(2).getName(), MercyHospital.getPatient(2).getDoctor().getName(), MercyHospital.getPatient(2).getPrescription().getDrug(), MercyHospital.getPatient(2).getDiagnosis());
        MercyHospital.getPatient(2).takePrescription();
        //create a random person and test function
        Person visitor = new Person("Jerry");
        visitor.sayHi();
    }
}