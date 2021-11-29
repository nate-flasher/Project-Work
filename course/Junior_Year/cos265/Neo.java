public abstract class Neo<ValType> {
    private int calls = 0;
    private boolean foundcalled = false;

    protected void increaseCalls() throws Exception {
        if(foundcalled) throw new Exception("Cannot check after found is called!");
        calls++;
    }

    protected void foundCalled() throws Exception {
        if(foundcalled) throw new Exception("Cannot check after found is called!");
        foundcalled = true;
    }

    protected int callsCount() {
        return calls;
    }

    public abstract int get(ValType i) throws Exception;
    public abstract void found1(ValType i) throws Exception;
}
