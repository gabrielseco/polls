[%bs.raw {|require('./app.css')|}];

let vDOM = Helpers.vDOM;

type state = {
  polls: list PollsList.poll,
  defaultForm: PollsList.poll, 
  form: PollsList.poll
};

type action =
  | HandleSubmit
  | UsernameHandler string
  | CharacterHandler string;

let onChangeInput event => {
  let key = (ReactDOMRe.domElementToObj (ReactEventRe.Form.target event))##name;
  let value = (ReactDOMRe.domElementToObj (ReactEventRe.Form.target event))##value;

  switch key {
    | "username" => UsernameHandler value
    | "character" => CharacterHandler value
    | _ => UsernameHandler value
  };
 };

 let handleSubmit event  => {
  ReactEventRe.Synthetic.preventDefault event;
  HandleSubmit;
 };

let component = ReasonReact.reducerComponent "App";

let make _children => {

  let getInitialState (): PollsList.poll => {
    {
        username: "",
        character: "",
        payment:false
    }
  };
  {
    ...component,
    reducer: fun action state =>
      switch action {
        | UsernameHandler value => ReasonReact.Update {...state, form: {...state.form, username: value} };
        | CharacterHandler value => ReasonReact.Update {...state, form: {...state.form, character: value} };
        | HandleSubmit => ReasonReact.Update {...state, polls: List.append state.polls [state.form], form: state.defaultForm };
      },
    initialState: fun () => {
      polls: [],
      defaultForm: getInitialState(),
      form: getInitialState()
    },
    render: fun { state, reduce } =>
      <div className="root">
        <Header title="Polls"/>
        <div className="main">
          <PollsList items=(state.polls)/>
          <form onSubmit=(reduce handleSubmit)>
            <p>(vDOM "Username ")</p>
            <input _type="text" name="username" value=(state.form.username) onChange=(reduce onChangeInput)/>
            <p>(vDOM "Character ")</p>
            <input _type="text" name="character" value=(state.form.character) onChange=(reduce onChangeInput) />
            <button>(vDOM "Send")</button>
          </form>
        </div>
        <Footer/>
      </div>
  }
};